#include <iostream>
#include <vector>
using namespace std;


string s;

int dfs(vector<vector<int>> &f, int i, int j) {

    if (f[i][j] != -1) {
        return f[i][j];
    }
    if (i > j) {
        f[i][j] = 0;
        return 0;
    }
    if (i == j) {
        f[i][j] = 1;
        return 1;
    }
    int res = 0;
    if (s[i] == s[j]) {
        res = dfs(f,i+1,j-1) + 2;
        f[i][j] = res;
        cout << "res1 " << i << " " << j << " " << res << endl; 
        return res;
    }
    res =  max(dfs(f,i+1,j),dfs(f,i,j-1));
    f[i][j] = res;
    cout << "res2 " << i << " " << j << " " << res << endl; 
    return res;
}

int dp(string &s) {
	int n = s.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	int ans = 1;
	for (int i = n-2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] != s[j]) {
				dp[i][j] = 0;
			} else {
				if (j-i<=2) {
					dp[i][j] = j-i+1;
				} else {
					dp[i][j] = dp[i+1][j-1] + 2;
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
} 


int main() {
    cin >> s;
    int m = s.size();
    vector<vector<int>> f(m,vector<int>(m,-1));
//    int ans = dfs(f,0,s.size()-1);
	int ans = dp(s);
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")

/**
开始 加入字符
结束 加入字符
开始和结束加入字符

*/
