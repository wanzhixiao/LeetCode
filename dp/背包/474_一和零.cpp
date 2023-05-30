#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    void countNumbers(string &t,vector<int> &cnts) {
        for(int i = 0; i < t.length(); i++) {
            ++cnts[t[i]-'0'];
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int t = strs.size();
        //1.初始化dp数组
        vector<vector<vector<int>>> dp(t+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        dp[0][0][0] = 0;
        //2.遍历
        for (int i = 1; i <= t; i++) {
            vector<int> cnts(2,0);
            countNumbers(strs[i-1],cnts);
            for (int j = 0; j <= m; j++) {      //j=0表示没有背包0容量
                for (int k = 0; k <= n; k++) {  //k=0表示没有背包1容量
                    if (j >= cnts[0] && k >= cnts[1]) {
                        dp[i][j][k] = max(dp[i-1][j-cnts[0]][k-cnts[1]]+1,dp[i-1][j][k]);
                    } else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[t][m][n];
    }
};

int main() {
	vector<string> strs = {"10", "0", "1"};
	int m = 1, n = 1;
	Solution solu;
	cout << solu.findMaxForm(strs,m,n) << endl;
	return 0;
} 
