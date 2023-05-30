#include<bits/stdc++.h>
#define N 101
using namespace std;

/*
背包问题
1.01背包
给定一个容量为C的背包，和n个物品，每个物品的重量是w[i],价值是v[i],从n个物品中挑选k（k<=n）个物品，并且
(w[0]+w[1]+w[2]+...+w[k]) <= C, 使得这k个物品的价值之和最大

例如：有三个物品，每个物品的重量和价值如下
       重量 价值
物品0	1	15
物品1	3	20
物品2	4	30
背包最大重量为4，问背包能背的物品最大价值是多少？



思路1：暴力法（枚举出每一种物品的组合）

思路2：递归法（自顶向下）

思路3：带记忆的递归（自顶向下）

思路4：动态规划（自底向上）
dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少。
*/

int zeroOneKnapsack1(vector<int> &weights, vector<int> &values,int C){
    int n = weights.size();
    int result = INT_MIN;
    assert (n == 3);      //假设物品的数量为3个
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(weights[i]<=C && result < values[i]){
            result = values[i];
            ans = {i};
        }
        for(int j=1;j<n;j++){
            if((weights[i]+weights[j])<=C && result < (values[i]+values[j])){
                result = values[i]+values[j];
                ans = {i,j};
            }
            for(int k=2;k<n;k++){
                if((weights[i]+weights[j]+weights[k])<=C && result < (values[i]+values[j]+values[k])){
                    result = values[i]+values[j]+values[k];
                    ans = {i,j,k};
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return result;
}

int zeroOneKnapsack2(vector<int> &weights, vector<int> &values,int C){
    int m = weights.size();
    vector<vector<int>> dp(m,vector<int>(C+1,0));
    for (int j = weights[0]; j <= C; j++) {
        dp[0][j] = values[0];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<=C;j++){
            if(j<weights[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i]]+values[i]);
            }
        }
    }
    return dp[m-1][C];
}

int zeroOneKnapsack3(vector<int> &weights, vector<int> &values,int C){
    int m = weights.size();
    vector<int> dp(C+1,0);

    for(int i=0;i<m;i++){
        for(int j=C;j>=weights[i];j--){
            dp[j] = max(dp[j],dp[j-weights[i]]+values[i]);
        }
    }
    return dp[C];
}

int zeroOneKnapsack4(vector<int> &weights, vector<int> &values,int C){
    int m = weights.size();
    vector<vector<int>> dp(m+1,vector<int>(C+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=C;j++){
            if(j<weights[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
            }
        }
    }
    return dp[m][C];
}


int main(){
    vector<int> weights = {1,3,4};
    vector<int> values = {15,20,30};
    int C = 4;
    cout << zeroOneKnapsack3(weights,values,C) << endl;
    return 0;
}