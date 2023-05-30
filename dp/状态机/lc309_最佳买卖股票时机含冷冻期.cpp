#include<iostream>
using namespace std;


/*
309
输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

122
输入：prices = [7,1,5,3,6,4]
输出：7
*/

class Solution {
public:
	//309含冷冻期 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][2] - prices[i], dp[i-1][0]);          //持有
            dp[i][1] = max(dp[i-1][0]+prices[i],dp[i-1][1]);             //未持有
            dp[i][2] = dp[i-1][1];                                       //冷冻
        }
        //返回的是手上没有股票的状态所能获得的收益 
        return max(dp[n-1][1],dp[n-1][2]);
    }
    
    //122 每天都可以进行买卖的最大利润 
	int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);   //未持有股票
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);   //持有股票
        }
        //返回的是手上没有股票的状态所能获得的收益 
        return dp[n-1][0];
    } 
};
 

int main() {
	
	return 0;
} 
