#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*
������������ word1 �� word2 ������ʹ�� word1 ��  word2 ��ͬ�������С������
����: word1 = "sea", word2 = "eat"
���: 2
����: ��һ���� "sea" ��Ϊ "ea" ���ڶ����� "eat "��Ϊ "ea"

˼·��
	ͬ�����������
	����dp[i][j] Ϊ�����ַ���word1 ��i��β���Ӵ� �����ַ���word2 ��j��β���Ӵ� ����Ҫ�Ĳ���
	��word1[i] == word2[j], ����Ҫ������ dp[i][j] = dp[i-1][j-1]
	��word1[i] != word2[j]  ��word1[0...i], ����word2[0...j]��ɾ��һ���� 
		dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]) ;
		
	��ʼ��
		dp[0][j] = j;		��ʾ��word2[0...j] �䵽 word1 = "" ��Ҫɾ��j�� 
		dp[i][0] = i; 		��ʾ��word1[0...i] �䵽 word2 = "" ��Ҫɾ��i�� 
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
