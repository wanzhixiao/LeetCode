#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int cnt = 0;
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i==j){
                    dp[i][j] = true;
                    continue;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = dp[i+1][j] || dp[i][j-1];
                } else {
                    if (j-i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }    
                if (!dp[i][j]) {
                	return false;
				}
            }
        }
        return true;
    }
    
    bool check(string &s,int left, int right) {
        for (; left < right; ) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    
    bool validPalindrome2(string s) {
        int n = s.length();
        int left = 0, right = n-1;
        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                return check(s,left+1,right) || check(s,left, right-1);
            }
        }
        return true;
    }
};

int main() {
	string s = "tebbem";
	Solution solu;
	cout << solu.validPalindrome(s) << endl;
	return 0;
}
