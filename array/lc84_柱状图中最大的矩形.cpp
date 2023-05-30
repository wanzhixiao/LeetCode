#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
柱状图中最大的矩形
题目：给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10；[5,6] 5*2 = 10 

思路1：暴力法
思路2：单调栈
维护一个单调第递增栈，栈中存元素的下标；栈顶下面一个元数，就是左边第一个比栈顶小的元素
当右侧遍历到一个比栈顶小的元素，那么，栈顶元素的面积就是	（右侧元素下标-栈顶的前一个元数下标-1）*栈顶下标对应的高度 
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMin(n,0);
        vector<int> rightMin(n,0);
        leftMin[0] = 0;
        rightMin[n-1] = n-1; 
        for (int i = 1; i < n; i++) {
        	leftMin[i] = heights[i] < heights[leftMin[i-1]] ? i : leftMin[i-1];
        	rightMin[n-1-i] = heights[n-1-i] < heights[rightMin[n-i]] ? n-1-i : rightMin[n-i];
		}
		for (int i = 0; i < n; i++) {
			int minH = max(heights[leftMin[i]],heights[rightMin[i]]);
		}
		return 0;
    }
    
    int largestRectangleArea2(vector<int>& heights) {
    	int n = heights.size();
    	stack<int> stk;
    	heights.push_back(-1);
    	int ans = 0;
    	for (int i = 0; i < n; i++) {
    		while (!stk.empty() && heights[i] < heights[stk.top()]) {
    			int idx = stk.top();
    			stk.pop();
    			int left = stk.empty() ? -1 : stk.top();   //左侧没有矩形的时候，栈为空，因为是单调递增栈，说明左侧的矩形高度都比栈顶的元素小，所以设置为-1 
    			ans = ans > (i-left-1)*heights[idx] ? ans : (i-left-1)*heights[idx];
			}
			stk.push(i);
		}
    	return ans;
	}
};

int main() {
	vector<int> heights = {2,1,5,6,2,3};
	Solution solu;
	cout << solu.largestRectangleArea2(heights) << endl;
	return 0;
} 
