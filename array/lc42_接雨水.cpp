#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
42.接雨水
题目: 给定n个非负整数表示每个宽度为1的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水 
思路1：单调栈
		用一个单调栈存数组的下标 ，从栈底到栈顶元素值依次减小
		栈顶元素大于当前元素，入栈；
		栈顶元素小于当前元素，取当前栈顶元素 ，待求面积的桶， (min(height[stk.top()],height[right]) - cutH)*(right-stk.top()-1) 
		
	能装水的前提：两边的桶都比中间的桶高
	
	细节：需要保持 stk.top() < right  , 即数组元素下标的先后顺序
	
思路2：动态规划 
	能装水的前提：两边的桶都比中间的桶高
	分别求当前柱子左侧最大值、右侧最大值 
	然后再遍历一次，用min(左侧最大值，右侧最大值）-height[i] 
*/
class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
        int left = 0, right = 0, ans = 0;
        stack<int> stk;
        while (right < n) {
            while (!stk.empty() && height[stk.top()] < height[right]) {
                int curH = height[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int minh = min(height[stk.top()],height[right]);
                int area = (right-stk.top()-1)*(minh-curH);
                ans = ans + area;
            }
            stk.push(right);
            right++;
        }
        return ans;
    }
    
    int trap2(vector<int>& height) {
		int n = height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        for (int i = 1; i < n; i++) {
            leftMax[i] = height[i] > leftMax[i-1] ? height[i] : leftMax[i-1];
        }
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = height[i] > rightMax[i+1] ? height[i] : rightMax[i+1];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i],rightMax[i]) - height[i];
        }
        return ans;
    }
};

int main() {
	vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution solu;
	cout << solu.trap2(vec) << endl;
	return 0;
}
