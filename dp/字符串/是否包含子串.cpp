#include<iostream>
#include<vector>
using namespace std;
 
bool contains(string &t, string &s) {
    int m = t.length();
    int n = s.length();
    if (m < n) {
        return false;
    }
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    for (int i = 0; i < m; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[i-1] == s[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s = "qwertty";
    string t = "rwy";
    cout << contains(s,t) << endl;
}


// t = "qwerty"
// s = "wry"

/*
1.dp[i][j]  表示t[0..i]是否包含 s[0..j]
2.
    dp[i][j] = dp[i-1][j-1] && t[i] == s[j]
    dp[i][j] = false t[i] != s[j]
dp[0][j]  = false;
dp[i][0] = true;

dp[len1][len2]
*/

