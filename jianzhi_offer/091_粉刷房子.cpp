#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
输入: costs = [[17,2,17],[16,16,5],[14,3,19]]
输出: 10
解释: 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
    最少花费: 2 + 5 + 3 = 10。


思路：
	dp[i][j]表示粉刷第i个房子使用第j种颜色所需要的最小花费
	dp[i][j] = cost[i][j] + min (dp[i+1][k] && k != j)

*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < 3; j ++) {
                int k = j, best = k;
                int min_cost = INT_MAX;
                while(k + 1 < 3) {
                    if (costs[i+1][k+1] < min_cost) {
                        min_cost = costs[i+1][k+1];
                        best = k + 1;
                    }
                    k++;
                }
                k = j;
                while(k - 1 >= 0) {
                    if(costs[i+1][k-1] < min_cost) {
                        min_cost = costs[i+1][k-1];
                        best = k - 1;
                    }
                    k--;
                }
                costs[i][j] += min_cost;
            }
        }
        int ans = INT_MAX;
        for (int i=0; i < 3; i++) {
            ans = ans < costs[0][i] ? ans : costs[0][i];
        }
        return ans;
    }
    
    //https://leetcode.cn/problems/JEj789/solution/by-nehzil-95v3/
   int minCost2(vector<vector<int>>& costs) {
	    int n = costs.size();
	    /* 定义 dp 数组 dp[i][k] 代表粉刷前 i 个房子的粉刷第 k 种颜色的最小花费 */
	    vector<vector<int>> dp(n,vector<int>(3));
	    /* dp 数组初始化 */
	    for(int i = 0; i < 3; i++)
	        dp[0][i] = costs[0][i];
	    /* 确定遍历数序进行递推 */
	    for(int i = 1; i < n; ++ i) {
	        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
	        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
	        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
	    }
	    /* 返回结果 */
	    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	}
    
    //网上的解法 2
    int minCost3(vector<vector<int>> &costs){
    	int m = costs.size();
        //初始化
        int a = costs[0][0];
        int b = costs[0][1];
        int c = costs[0][2];
        for (int i = 1; i < m; i++) {
            int a1 = min(b, c) + costs[i][0];
            int b1 = min(a, c) + costs[i][1];
            int c1 = min(a, b) + costs[i][2];
            a = a1;
            b = b1;
            c = c1;
        }
        return min(a, min(b, c));
	}
};

int main(){
	return 0;
}
