#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
将一个字符串分割成回文串所需要的最少次数
先用预处理字符串，以O(1)的时间复杂度确定 s[j...i]是否为 回文字符串; 回文串的判读使用中心扩散法
	从内向外， 如果j-i>=2 && s[i] == s[j] ; dp[i][j] = dp[i+1][j-1];  如果j-i <=2 && s[i]==s[j] dp[i][j] = true; 
				dp[i][j] = false		,s[i] != [j] 
				
		for(int i=n-1; i>=0; i--) {
			for(int j=i; j<n; j++) {
				if (s[i] != s[j]) {
					dp[i][j] = false;
				} else {
					if(j-i <= 2) {
						dp[i][j] = true;
					} else {
						dp[i][j] = dp[i+1][j-1];
					}
				}
			}
		}
	
定义 f[i]为以i结尾的最少分割次数
f[i] = min(f[j]} + 1;  其中，0<=j <i; 表示从f[j]基础上再加1, 如果字符串s[j...i]是回文串
初始化，f[i] = INT_MAX 
*/
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) {
            return 0;
        }
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j-i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        vector<int> f(n,INT_MAX);
        for(int i = 0; i < n; i++) {
            if(dp[0][i]) {
                f[i] = 0;
            } else {
                for(int j = 0; j < i; j++) {
                    if (dp[j+1][i]) {
                        f[i] = min(f[i], f[j]+1);
                    }
                }
            }
        }
        return f[n-1];
    }
};

int main(){
	string str = "ababba";
	Solution s;
	cout << s.minCut(str) << endl;
	return 0;
}
