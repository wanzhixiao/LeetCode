#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*

���룺s = "rabbbit", t = "rabbit"
�����3
���ͣ�
����ͼ��ʾ, �� 3 �ֿ��Դ� s �еõ� "rabbit" �ķ�����
rabbbit
rabbbit
rabbbit

˼·�� 
//dp[i][j]��ʾs[0...i]�п������t[0...j]�ĸ���
//dp[0][j] = 0; dp[i][0] = 1;
//��s[i] == t[j] ����ʹ��s[i],ѡ����s[0..i-1]���t[0..j-1],���߲�ʹ��s[i]����s[0..i-1]���t[0..j]  ;   dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
//��s[i] != t[j] ֻ��ѡ����s[0..i-1]���t[0..j]�� dp[i][j] = dp[i-1][j];

��ʼ����
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
