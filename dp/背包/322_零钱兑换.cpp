#include<iostream>
#include<vector>
using namespace std;

/*
零钱兑换：给定一个整数数组coins, 和一个金额为amount, 输出最少使用的钱币个数，coins数组中的数可以重复使用 
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1 

思路：
	钱币可以使用，是完全背包问题 
	dp[i][j]表示使用[0...i]个物品组成金额j所需要的硬币数
	dp[i][j] = min(dp[i][j],dp[i-1][j-k*coins[i]]+k) , j >= k*coins[i]
	dp[i][j] = dp[i][j], j < k*coins[i]
	
	初始化
	dp[0][0] = 0;
	dp[0][i] 空集合中中无法选出任何硬币组成金额， dp[0][j] = INT_MAX， 
	dp[i][0] 没有意义，金额为0不能由硬币组成 , dp[0][j] = INT_MAX， 
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		vector<vector<int>> dp(n+1,vector<int>(amount+1,amount+1));
		dp[0][0] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= amount; j++) {		//需要组成的数为0,即背包容量为0的时候 
				for (int k = 0; k  <= j/coins[i-1]; k++) {
//					cout <<"k * coins[i]==" << k * coins[i-1]<< endl;
					dp[i][j] = min(dp[i][j],dp[i-1][j-k*coins[i-1]]+k);
				}
			}
		}
		return dp[n][amount] == amount+1 ? -1 : dp[n][amount];
    }
    
    int coinChange2(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,amount+1);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= amount; j++) {		//需要组成的数为0,即背包容量为0的时候 
                if (j >= coins[i-1]) {
                    dp[j] = min(dp[j-coins[i-1]] + 1,dp[j]);
                }
			}
		}

		return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

int main() {
	vector<int> conis = {186,419,83,408};
	int amount = 6249;
	Solution solu;
	
	cout << solu.coinChange(conis,amount) << endl;
	
	return 0;
} 
