#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<int> height(n,0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                } else {
                    height[j] = 0;
                }
            }
            ans = max(ans,getArea(height));
        }
        return ans;
    }

    int getArea(vector<int> &height) {
        height.push_back(-1);
        int n = height.size();
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[stk.top()] >= height[i]) {
                int h = height[stk.top()];
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                int area = (i-left-1)*h;
                ans = max(ans,area);
            }
            stk.push(i);
        }        
        return ans;
    }
};

int main() {
//	cout << (3<<1) << " " << (2>>1) << endl; 
	return 0;
}
