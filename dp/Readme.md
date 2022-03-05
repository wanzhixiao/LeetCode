区间dp  

dp[i][j] = max/min{(dp[i,j],dp[i,k]+dp[k+1,j])+cost}  

第一种枚举方式  
```java
for(int i=n-1;i>=0;i--){       //枚举左端点
    for(int j=i;j<n;j++){    //枚举右端点
        for(int k=i;k<j;k++){  //枚举中间结点
            dp[i][j] = max/min{dp[i][k]+dp[k+1][j]+cost}
        }   
    }
}
```
另一种枚举方式，先计算小区间，再计算大区间
```java
for(int len=2;len<=n;len++){       //枚举区间长度
    for(int i=0;i+len-1<n;i++){    //枚举左端点
        int j = i+len-1;
        for(int k=i;k<j;k++){      //中间结点
            dp[i][j] = max/min{dp[i][k]+dp[k+1][j]+cost}
        }   
    }
}

```
1.矩阵链乘法
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
//				cout << "i=" << i << " k=" << k << " j=" << j << endl;
			}
		}
	}
	cout << dp[0][n-1] << endl;
	
	return 0;
} 

/*
i=0 j=1
i=1 j=2
i=2 j=3
i=3 j=4
i=0 j=2
i=1 j=3
i=2 j=4
i=0 j=3
i=1 j=4
i=0 j=4
*/


2.石子合并  
dp[i][j] = min(dp[i][p] + dp[p + 1][j] + sum(i, j)) | i <= p < j  
dp[i][i] = 0  



3.整数拆分  
给定一个正整数?n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。  

示例 1:  
输入: 2  
输出: 1  
解释: 2 = 1 + 1, 1 × 1 = 1。  

示例2:  
输入: 10  
输出: 36  
解释: 10 = 3 + 3 + 4, 3 ×3 ×4 = 36。  
 

思路：   
```c++
n拆分成至少两个以上的数  

f(n) = i*f(n-i)	 //对n-i继续拆分   
f(n) = f(i)(n-i) //对i继续拆分   
f(n) = f(i)f(n-i) //对i和n-i继续拆分  

i与n-i对称,考虑其中一种,i*(n-i)和i*f(n-i)包括所有情况，也包括f(i)f(n-i)   
所以f(n) = max(i*(n-i),i*f(n-i))  
//递归树解法   
int dfs(n){  
	if(n<2){  
		return 0;  
	}   
	if(n==2){  
		return 1;  
	}
	//枚举i  
	int res = 0;  
	for(int i=1;i<n;i++){  
		res = max(res,max(i*(n-i),i*dfs(n-i)));  
	}   
	return res;  
} 
//带记忆的递归  
int dfs(n){  
	if(n==2){  
		return 1;  
	}  
	//枚举i  
	if(memo[n]!=-1){  
		return meno[n];  
	}   
	int res = 0;  
	for(int i=1;i<n;i++){  
		res = max(res,max(i*(n-i),i*dfs(n-i)));  
	}   
	return meno[n] = res;  
}   
```
//动态规划  
1、确定状态(子问题) ,拆与不拆,拆,n拆成i,n-i,  
2、确定转移方程(原问题与子问题的关系),n-i是否继续拆？  是dp[n-i],否n-i,那么  
	dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]))  
 	
3、确定base(边界条件)   
	0,1不能拆(原子数),dp[0] = dp[1] = 1;dp[2] = 2;2=1+1, 1*1  
	初始化dp[i] = 0; i>=2; 未拆,数小于2时，乘积设置为0   
	
	dp[2] = max(dp[2],1*(2-1),1*dp[2-1]) = max(0,1,1) = 1;  
	dp[3] = max(dp[3],1*(3-1),1*dp[3-1]) = max(0,2,1*dp[2]) = 2; 即：3=1+2,1*2=2   
	 




 
