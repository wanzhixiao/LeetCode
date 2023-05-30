#include<iostream>
#include<vector>
#include<stack>
using namespace std; 

/*
维护一个单调递增栈，栈中存柱子的高度
当当前元素高于栈顶元素时，
面积 = (i - stk.top()) * height[stk.top()];  
height[stk.top()]为当前最低的高，因此只需求 i到stk.top()都是高度为height[stk.top()], w=i-stk.top() 

输入：heights = [2,1,5,6,2,3]
输出：10

求6的面积，找到左右最小的下标相减 w = (i - left - 1 ) * 6
left怎么确定？

left = stk.empty() ? -1 : stk.top();
因为栈为空，所以左侧的柱子都可以看做高度比栈顶柱子高度小 

如果数组为递增的
1,2,3; 栈不能清空；所以需要在右侧存一个0 
*/ 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int ans = 0;
        stack<int> stk;
        heights.push_back(0);
        int n = heights.size();
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
            	int h = heights[stk.top()];
          		stk.pop();
          		int left = stk.empty() ? -1 : stk.top(); 	//左侧柱子的下标 
                ans = max(ans, (i-left-1)*h);
            }
            stk.push(i);
        }
        return ans;
    }
};

/*
用例 ： [2,1,2] 
栈元素的变化
[2]					ans = 0
[1]					ans = max(ans,height[i]) = max(0,2) =  2
[1,2]               ans = 2
 [1]                ans = max(ans,height[stk.top()]*(3-stk.top())) = max(2,2*(3-2)) = 2
 [0] 				ans = max(ans,height[stk.top()]*(3-stk.top())) = max(2,1*(3-1)) = 2
 第一个2已经不在栈中， 因此 求得最大矩形面积为2 
*/ 

int main() {
	vector<int> height = {2,1,2};
	Solution solu;
	cout << solu.largestRectangleArea(height) << endl;
	return 0;
}
