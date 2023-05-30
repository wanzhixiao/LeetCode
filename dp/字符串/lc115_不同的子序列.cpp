#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
    	int m = s.length();
        int n = t.length();

        vector<vector<uint64_t>> dp(m+1,vector<uint64_t>(n+1,0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
	string s = "babgbag";
	string t = "bag";
	Solution solu;
	cout << solu.numDistinct(s,t) << endl;
	return 0;
} 
