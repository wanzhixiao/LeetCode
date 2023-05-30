#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*

输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit

思路： 
//dp[i][j]表示s[0...i]中可以组成t[0...j]的个数
//dp[0][j] = 0; dp[i][0] = 1;
//当s[i] == t[j] 可以使用s[i],选择由s[0..i-1]组成t[0..j-1],或者不使用s[i]，由s[0..i-1]组成t[0..j]  ;   dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
//当s[i] != t[j] 只能选择由s[0..i-1]组成t[0..j]； dp[i][j] = dp[i-1][j];

初始化：
	dp[0][j] = 0;
	dp[i][0] = 1;
	dp[0][0] = 1 
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n) {
            return 0;
        }
        vector<vector<uint64_t>> dp(m+1, vector<uint64_t>(n+1,0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }
        dp[0][0] = 1;
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
	string s1 = "babgbag";
	string t = "bag";
	Solution s;
	cout << s.numDistinct(s1,t) << endl; 
	return 0;
}
