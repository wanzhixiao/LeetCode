#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
���룺word1 = "abcc", word2 = "aab"
�����true
���ͣ�������һ���ַ������±� 2 �͵ڶ����ַ������±� 0 ��֮��õ� word1 = "abac" �� word2 = "cab" ������ 3 ����ͬ�ַ���


˼·��
	dp[i][j]����Ϊword1[0...i]��word2[0...j]��ͬ�ַ��Ĳ�����
	if word1[i] == word2[j]
		dp[i][j] = dp[i-1][j-1]
	else 
		dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1]
		
	��ʼ��
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
