#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
������Ӵ���
	����dp[i][j]Ϊs[i...j]�Ƿ�Ϊ���Ĵ���s[i] == s[j] dp[i][j] = dp[i-1][j-1]
	�߽����� dp[i][i] = 1; 
�����������
	����dp[i][j]Ϊs[i...j]������������г��ȣ�
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n==1) {
            return s;
        }
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        int start = 0, len = 1;
        for (int i = n-2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j-i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if (dp[i][j] && (j-i+1)>len) {
                    start = i;
                    len = j-i+1;
                }
            }
        }
        return s.substr(start, len);
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        //����dp[i][j]Ϊs[i...j]������������� 
        vector<vector<int>> dp(n,vector<int>(n,false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
//        int start = 0, maxlen = 1; 
        for (int i = n-2; i >= 0; i--) {
        	for (int j = i+1; j < n; j++) {
        		if (s[i] != s[j]) {
        			dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
				} else {
					if (j-i <= 2) {
						dp[i][j] = j-i+1;
					} else {
						dp[i][j] = dp[i+1][j-1]+2;
					}
				}
				cout << i << " " << j << " " << dp[i][j] << endl; 
			}
		}
		return dp[0][n-1];
    }
};


int main() {
	string s = "aacabdkacaa";
	Solution solu;
	cout << solu.longestPalindromeSubseq(s) << endl;
	return 0;
} 
