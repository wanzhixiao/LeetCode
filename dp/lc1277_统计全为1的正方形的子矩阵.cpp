#include<iostream>
#include<vector>

/*
1277 统计全为1的正方形的子矩阵
思路同221题 

[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
15

[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
7
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));

        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] == 1 ? 1 : 0;
            ans = ans + dp[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = matrix[0][j] == 1 ? 1 : 0;
            ans = ans + dp[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                } else {
                    dp[i][j] = 0;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

int main() {
	return 0;
} 
