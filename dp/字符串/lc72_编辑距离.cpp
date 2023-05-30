#include<string>
#include<vector>
#include<iostream>
using namespace std;

/*
�༭���룺
	dp[i][j]��ʾ ��word1[0...i]�༭��word2[0...j]����Ҫ�����ٱ༭����
	dp[i][j] = dp[i-1][j-1] ���word1[i] == word2[j]	, ��ʾ��ǰ���費��Ҫ����Ĳ�����ֻ��Ҫ��word1[...i-1]��� word2[...j-1]�Ĳ������� 
	dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]), word1[i] != word2[j], ��ʾ���滻�����롢ɾ����ѡһ����С�� +1 
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
