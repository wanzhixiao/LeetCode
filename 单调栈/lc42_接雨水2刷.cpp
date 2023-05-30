#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
矩形面积 = 宽*高 
高 = min (height[right], height[left]) - height[cur]
宽 = min(right-left-1)

需要维护一个单调递减栈，栈内的元素为柱子的高度，且依次递减 
*/ 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int h = height[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int area = (i-stk.top()-1)*(min(height[i],height[stk.top()]) -h);
                ans = ans + area;
            }
            stk.push(i);
        }
        return ans;
    }
};

int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution solu;
	cout <<  solu.trap(height) << endl;
	return 0; 
} 
