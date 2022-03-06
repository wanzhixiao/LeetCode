#include<bits/stdc++.h>

using namespace std;

typedef struct matrix{
	int r,c;
}matrix;

int main(){
	int n = 4;
	int p[n+1] = {3,5,4,8,2};
	int dp[n][n];

   //初始化 
   matrix m[n]={0,0};
   for (int i = 0; i < n; i++)
    {
  		m[i].r = p[i];
  		m[i].c = p[i+1];
    	dp[i][i] = 0;
    }
	
	for(int r=1;r<n;r++){ //枚举区间长度 
		for(int i=0;i<n-r;i++){ //枚举左端点 
			
			int j = i+r;  //枚举右端点 
			dp[i][j] = 65535;
			
			//从小到达求解问题 
			for(int k=i;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+m[i].r*m[k].c*m[j].c);
				cout << "i=" << i << " k=" << k << " j=" << j << endl;
			}
		}
	}
	cout << dp[0][n-1] << endl;
	
	return 0;
} 

/*
i=0 k=0 j=1
i=1 k=1 j=2
i=2 k=2 j=3
i=0 k=0 j=2
i=0 k=1 j=2
i=1 k=1 j=3
i=1 k=2 j=3
i=0 k=0 j=3
i=0 k=1 j=3
i=0 k=2 j=3
*/
