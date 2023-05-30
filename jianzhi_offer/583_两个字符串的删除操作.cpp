#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*
给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"

思路：
	同最长公共子序列
	定义dp[i][j] 为处理字符串word1 以i结尾的子串 ，和字符串word2 以j结尾的子串 所需要的步数
	若word1[i] == word2[j], 不需要操作， dp[i][j] = dp[i-1][j-1]
	若word1[i] != word2[j]  从word1[0...i], 或者word2[0...j]中删除一个， 
		dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]) ;
		
	初始化
		dp[0][j] = j;		表示将word2[0...j] 变到 word1 = "" 需要删除j次 
		dp[i][0] = i; 		表示将word1[0...i] 变到 word2 = "" 需要删除i次 
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,502));
        for (int i = 0; i <= n; i++) {
            dp[0][i] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[j][0] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
	string word1 = "sea";
	string word2 = "eat";
	Solution s;
	cout << s.minDistance(word1,word2) << endl;
	return 0;
}
