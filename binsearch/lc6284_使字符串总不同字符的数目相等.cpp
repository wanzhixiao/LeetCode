#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
输入：word1 = "abcc", word2 = "aab"
输出：true
解释：交换第一个字符串的下标 2 和第二个字符串的下标 0 。之后得到 word1 = "abac" 和 word2 = "cab" ，各有 3 个不同字符。


思路：
	dp[i][j]定义为word1[0...i]和word2[0...j]不同字符的差异数
	if word1[i] == word2[j]
		dp[i][j] = dp[i-1][j-1]
	else 
		dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1]
		
	初始化
	dp[0][j] = j;
	dp[i][0] = i;
	dp[0][0] = 1; 
*/
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j ++) {
            dp[0][j] = j;
        }
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
                cout << "i=" << i << " j="<< j << " dp[i-1][j-1]=" << dp[i-1][j-1] << " dp[i][j]=" << dp[i][j] << endl; 
            }
        }
        return dp[m][n] <= 1;
    }
};

int main() {
	
	return 0;
}
