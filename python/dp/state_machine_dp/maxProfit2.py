from functools import cache
from dgl.container import List
from transformer.conf import inf

'''
买卖股票的最佳时机，无限次交易
约束
1.每次手上只能有一支股票
2.卖出前必须先买入
'''

class Solution(object):
    def maxProfit1(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 每次手上只能有一支股票
        # 卖出前必须先买入
        # 持有 = max(上一天持有，上一天未持有-prices[i])
        # 未持有 = max(上一天持有+prices[i], 上一天未持有）
        n = len(prices)
        dp = [[0]*2]*n
        dp[0][0] = -prices[0]           # 0, 持有，1 未持有

        for i in range(1,n):
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i])
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i])
        return dp[n-1][1]

    # dp空间优化
    def maxProfit2(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 每次手上只能有一支股票
        # 卖出前必须先买入
        # 持有 = max(上一天持有，上一天未持有-prices[i])
        # 未持有 = max(上一天持有+prices[i], 上一天未持有）
        n = len(prices)
        dp = [0]*2
        dp[0] = -prices[0]

        for i in range(1,n):
            dp[0] = max(dp[0],dp[1]-prices[i])
            dp[1] = max(dp[1],dp[0]+prices[i])
        return dp[1]

    # 贪心算法，只与上升的区间有关，且区间的diff可以累加
    def maxProfit3(self, prices):
        n = len(prices)
        ans = 0
        for i in range(1,n):
            diff = prices[i] - prices[i-1]
            if diff > 0:
                ans += diff
        return ans

    #暴力搜索
    def maxProfit4(self, prices: List[int]) -> int:
        ans = 0

        def dfs(prices, profit, pos, status):
            nonlocal ans
            if pos == len(prices):
                ans = max(ans, profit)
                return
            # 对于当前的数，操作或者不操作
            # 1. 不操作
            dfs(prices, profit, pos + 1, status)

            # 2. 操作
            # 0 表示不持有股票，1表示持有股票，
            if status == 0:  # 未持有
                dfs(prices, profit - prices[pos], pos + 1, 1)
            else:  # 有股票
                dfs(prices, profit + prices[pos], pos + 1, 0)

        dfs(prices, 0, 0, 0)
        return ans

    #记忆化搜索
    def maxProfit(self, prices: List[int]) -> int:
        @cache
        def dfs(i, hold):
            if i < 0:
                return -inf if hold else 0
            if hold:
                return max(dfs(i - 1, False) - prices[i], dfs(i - 1, True))
            return max(dfs(i - 1, False), dfs(i - 1, True) + prices[i])

        return dfs(len(prices) - 1, False)

    # 修改成dp
    def maxProfit(self, prices: List[int]) -> int:

        n = len(prices)
        f = [[0] * 2 for _ in range(n + 1)]
        f[0][1] = -inf

        for i in range(1, n + 1):
            f[i][1] = max(f[i - 1][0] - prices[i - 1], f[i - 1][1])
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1])
        return f[n][0]

    # dp空间优化
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        f = [0] * 2
        f[1] = -inf
        for i in range(1, n + 1):
            f[1] = max(f[0] - prices[i - 1], f[1])
            f[0] = max(f[0], f[1] + prices[i - 1])

        return f[0]

# python创建二维数组
# https://zhuanlan.zhihu.com/p/88197389

#参考： https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/