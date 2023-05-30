#include <iostream>
#include <string>
#include<vector>
using namespace std;

/*
len(a) < len(b) 
*/ 
string longestCommonSubstr() {
   string a, b;
   cin >> a >> b;
   if (a.size() > b.size()) {
        string c = a;
        a = b;
        b = c;
   }
   int m = a.size(), n = b.size();
   vector<vector<int>> dp(m,vector<int>(n,0));  
   for (int i = 0; i < m; i++) {
        dp[i][0] = (a[i]==b[0]) ? 1 : 0;
   }
   for (int j = 0; j < n; j++) {
        dp[0][j] = (a[0]==b[j]) ? 1 : 0;
   }
   for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
   }
   int start = 0, maxlen = 0;
   for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] > maxlen) {
                maxlen = dp[i][j];
               	start = i - maxlen + 1;
            }
        }
   }
   return a.substr(start, maxlen);
}

int main() {
    string a,b;
    cin >> a >> b;
	int m = a.size(), n = b.size();
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    int maxlen = 0;
	for (int i = 1; i <= m; i++ ) {
		for (int j = 1; j <= n; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
            maxlen = max(dp[i][j],maxlen);
		}
	} 
	cout << maxlen << endl;
}
