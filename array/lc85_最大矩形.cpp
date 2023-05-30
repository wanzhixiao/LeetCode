#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
	{
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n+1,0);
        int ans = 0;
        for (int i = 0; i <m; i++) 
		{
            stack<int> stk;
            for (int j = 0; j < n; j++) 
			{
                if (matrix[i][j] == '1') 
				{
                    height[j]++;
                } 
				else 
				{
                    height[j] = 0;
                }
            }
            ans = max(ans,maxArea(height));
        }
        return ans;
    }
    
    int maxArea(vector<int>& heights) {
		int ans = 0;
        stack<int> stk;
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

int main() {
	
	return 0;
} 
