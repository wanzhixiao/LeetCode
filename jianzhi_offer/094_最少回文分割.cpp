#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
��һ���ַ����ָ�ɻ��Ĵ�����Ҫ�����ٴ���
����Ԥ�����ַ�������O(1)��ʱ�临�Ӷ�ȷ�� s[j...i]�Ƿ�Ϊ �����ַ���; ���Ĵ����ж�ʹ��������ɢ��
	�������⣬ ���j-i>=2 && s[i] == s[j] ; dp[i][j] = dp[i+1][j-1];  ���j-i <=2 && s[i]==s[j] dp[i][j] = true; 
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
	
���� f[i]Ϊ��i��β�����ٷָ����
f[i] = min(f[j]} + 1;  ���У�0<=j <i; ��ʾ��f[j]�������ټ�1, ����ַ���s[j...i]�ǻ��Ĵ�
��ʼ����f[i] = INT_MAX 
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
