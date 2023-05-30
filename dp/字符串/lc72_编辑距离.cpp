#include<string>
#include<vector>
#include<iostream>
using namespace std;

/*
编辑距离：
	dp[i][j]表示 将word1[0...i]编辑到word2[0...j]所需要的最少编辑次数
	dp[i][j] = dp[i-1][j-1] 如果word1[i] == word2[j]	, 表示当前步骤不需要额外的操作，只需要将word1[...i-1]变成 word2[...j-1]的操作次数 
	dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]), word1[i] != word2[j], 表示从替换、插入、删除中选一个最小的 +1 
*/

class Solution {
public:
 int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
	string word1 = "horse", word2 = "ros";
	Solution s;
	cout << s.minDistance(word1,word2) << endl; 
	return 0;
}

//https://www.bilibili.com/video/BV15h411Z7Qd/?spm_id_from=333.337.search-card.all.click&vd_source=843e98298bc70b0e35331918314486ce
