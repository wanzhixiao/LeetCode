#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        if (m <= 1 || n <= 1) {
            return dp;
        }
        
        for (int i = 0; i < m-1; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n-1; j++) {
           dp[0][j] = 1;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] != grid[i-1][j-1]) {
                   dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = dp[i-1][j-1];
                }
               cout << dp[i][j] << " ";
           }
			cout << endl;
        }
		// 如何计算下标左下角？？        
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		
			}
		}
        
        cout << endl;
        
        return {};
    }
    
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        if (m <= 1 || n <= 1) {
            return dp;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //统计左上
                set<int> lup;
                int r = i-1, c = j-1;
                while (r>=0 && c >= 0) {
                    lup.insert(grid[r--][c--]);
                }
                int sz1 = lup.size();
                lup.clear();
                //统计右下
                r = i+1, c = j+1;
                while (r < m && c < n) {
                    lup.insert(grid[r++][c++]);
                }
                int sz2 = lup.size();
                int t = abs(sz1-sz2);
                cout << i << " " << j << " " << sz1 << " " << sz2 << endl;
            }
            cout << endl;
        }
        
        return {};
    }
};

int main() {
	vector<vector<int>> grid = {{1,2,3},{3,1,5},{3,2,1}};
	Solution solu;
	solu.differenceOfDistinctValues(grid);
	return 0;
} 
