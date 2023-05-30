#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int n = 4;
	vector<int> dp(n+1,0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		int j = 0;
		int p = 1;
		while (p < i) {
			dp[i] += dp[i-p];
			++j; 
			p = pow(2,j);
		}
	} 
	cout << dp[n] << endl;
	return 0;
} 


/*
n = 4
start = 0

k = 1, 2, 4, 8, 16
0 ->1->2->3->4
0->1->2->4
0->1->3->4
0->2->4
0->2->3->4

i > = 4
dp[i] = dp[i-1]+dp[i-2]+dp[i-4]
*/ 
