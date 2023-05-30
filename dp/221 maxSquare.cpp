#include<iostream>
#include<vector>
#include<string.h>
#define N 101
int matrix[N][N];

using namespace std;

/*
�������������������������
���Ͻǵ�0
	0 1 1
	1 1 1 
	1 1 1
�Ϸ���0
	1 0 1
	1 1 1 
	1 1 1
��ߵ�0 
	1 1 1
	0 1 1 
	1 1 1
	
�����������ȡ��С 
����dp[i][j]��ʾ��i��jΪ���½ǵ���������� 
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

���� 
[
	[1,0,1,0],
	[1,0,1,1],
	[1,0,1,1],
	[1,1,1,1],
]


dp���� 
[
	[0,1,1,1]
	[0,1,2,2]
	[0,1,2,3]	
]

*/ 
