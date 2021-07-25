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
石子合并  
dp[i][j] = min(dp[i][p] + dp[p + 1][j] + sum(i, j)) | i <= p < j  
dp[i][i] = 0  