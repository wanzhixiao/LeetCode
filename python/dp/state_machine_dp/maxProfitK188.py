'''
买卖股票的最佳时机 188
约束
1. 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易
2. 不能同时参与多比交易， 必须在再次购买前出售掉之前的股票

思路：
    dfs(i, k, True) = max(dfs(i-1, k, True), dfs(i-1, k-1, False) - prices[i])
    dfs(i, k, False) = max(dfs(i-1, k, False), dfs(i-1, k, True) + prices[i])

边界条件
    当没有交易次数的时候，返回-inf
    当属于第0天是，hold, 返回-inf, 非hold, 返回0
'''

class Solution:
    #记忆化搜索
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        #使用cache装饰器类似查表，参数只能是可哈希的参数列表
        @cache
        def dfs(i, j, hold):
            if j < 0:  # 没有交易次数了
                return -inf
            if i < 0:  # 小于第0天
                return -inf if hold else 0
            if hold:
                return max(dfs(i - 1, j, True), dfs(i - 1, j - 1, False) - prices[i])       #1
            return max(dfs(i - 1, j, False), dfs(i - 1, j, True) + prices[i])               #2
        return dfs(n - 1, k, False)                                                         #3

    # 递推
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        #初始化成-inf
        f = [[[-inf] * 2 for _ in range(k + 2)] for _ in range(n + 1)]

        for i in range(1, k + 2):
            f[0][i][0] = 0

        for i in range(0, n):
            for j in range(1, k + 2):
                f[i + 1][j][0] = max(f[i][j][0], f[i][j - 1][1] + prices[i])    #2          买的时候使用了一次操作数
                f[i + 1][j][1] = max(f[i][j][1], f[i][j][0] - prices[i])        #1          注意买和买智能算一次，卖的时候不算操作数

        return f[n][k + 1][0]                                                   #3

    # 递推空间优化， 0/1背包，第j次操作数的容量下，买或者不买
    def maxProfit(self, prices: List[int], k: int) -> int:
        # write code here
        n = len(prices)

        #初始化成-inf,1-k+2， 最多k+2次， 0,1,2,...k,  一共n天，
        dp = [[-inf] * 2 for _ in range(k+2)]

        for i in range(1,k+2):
            dp[i][0] = 0
        # dp[0][1][1] = -prices[0]

        for i in range(n):
            for j in range(k+1,0,-1):
                #因为要算dp[i-1],  用dp[i+1] <- dp[i]
                dp[j][0] = max(dp[j][0], dp[j][1]+prices[i])
                dp[j][1] = max(dp[j][1], dp[j-1][0]-prices[i])

        return dp[k+1][0]