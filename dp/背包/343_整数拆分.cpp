#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
 
class Solution {
private:
    int memo[60]; 
public:
    int integerBreak(int n) {
        memset(memo, -1, sizeof(memo));
        return dfs(n);
    }
    
    int dfs(int n) {
        if (n == 1) {
            return 1;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int ret = 0;
        for (int i = 1; i < n; i++) {
        	//²ð»òÕß²»²ð 
            int cur = max(dfs(i) * (n-i), i*(n-i));
            ret = max(ret, cur);
        }
        memo[n] = ret;
        return ret;
    }
    
    
    int integerBreak2(int n) {
		vector<int> dp(n+1,0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
            int ret = 0;
            for (int j = 1; j < i; j++) {
                ret  = max(dp[j]*(i-j), j*(i-j));
                dp[i] = max(ret, dp[i]);
            }
		} 
		return dp[n];
    }
    
};
/*
            2
         -1/ 
          1
       -1/
       1
*/

int main() {
	Solution solu;
	int n = 58;
	cout << solu.integerBreak(n) << endl;
	return 0;
}
