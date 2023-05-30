#include<iostream>
#include<vector>
#include<string.h>
#define N 101
int matrix[N][N];

using namespace std;

/*
矩形中最大的正方形面积受限于
左上角的0
	0 1 1
	1 1 1 
	1 1 1
上方的0
	1 0 1
	1 1 1 
	1 1 1
左边的0 
	1 1 1
	0 1 1 
	1 1 1
	
因此是三者中取最小 
定义dp[i][j]表示以i，j为左下角的正方形面积 
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 
*/ 

int maxSquareArea(int m, int n){
	int ans = 0;
	int dp[m][n] = {0};
	for (int i = 0; i < m; i++) {
		dp[i][0] = matrix[i][0] == 1 ? 1 : 0;
		ans = max(ans,dp[i][0]);
	}
	for (int j = 0; j < n; j++) {
		dp[0][j] = matrix[0][j] == 1 ? 1 : 0;
		ans = max(ans,dp[0][j]);
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (matrix[i][j] == 1) {
				dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			} else {
				dp[i][j] = 0;
			}
			ans = max(ans,dp[i][j]);
		}
	}
	return ans*ans;
}

int main() {
	memset(matrix,0,sizeof(matrix));
	int idx[][2] = {{0,1},{0,2},{0,3},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3}};
	for (int i = 0; i < 9; i++) {
		int x = idx[i][0], y = idx[i][1];
		matrix[x][y] = 1;
	}
	
	cout << maxSquareArea(3,4) << endl;
	return 0;
} 


/*
[
	[0,1,1,1]
	[0,1,1,1]
	[0,1,1,1]
]

用例 
[
	[1,0,1,0],
	[1,0,1,1],
	[1,0,1,1],
	[1,1,1,1],
]


dp数组 
[
	[0,1,1,1]
	[0,1,2,2]
	[0,1,2,3]	
]

*/ 
