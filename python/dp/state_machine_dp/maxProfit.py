
'''
买卖股票的最佳时机1
prices = [7,1,5,3,6,4]
1. 只允许交易一次
2. 在同一天不同同时买卖
'''
from typing import List


class Solution:
    #1. 暴力法 198 / 211 个，超时
    def maxProfit1(self, prices: List[int]) -> int:
        n = len(prices)
        ans = 0
        for i in range(0,n-1):
            profit = 0
            for j in range(i+1,n):
                profit = max(profit, prices[j]-prices[i])
            ans = max(ans, profit)
        return ans

    #2. 单调栈
    def maxProfit2(self, prices: List[int]) -> int:
        n = len(prices)
        ans = 0
        stack = []
        for i in range(0,n):
            while len(stack) > 0 and stack[-1] >= prices[i]:
                ans = max(ans, stack[-1]-stack[0])
                stack.pop()
            stack.append(prices[i])

        while len(stack) > 0:
            ans = max(ans, stack[-1] - stack[0])
            stack.pop()
        return ans
    #3. 线段树

    #4. 贪心法
    def maxProfit3(self, prices: List[int]) -> int:
        n = len(prices)
        ans = 0
        min_price = prices[0]

        for i in range(1,n):
            min_price = min(min_price, prices[0])
            ans = max(ans, prices[i]-min_price)
        return ans

    # 贪心法递归
    def maxProfit3(self, prices: List[int]) -> int:
        min_price, ans = prices[0], 0
        def dfs(prices, i):
            if i == len(prices):
                return
            nonlocal min_price, ans
            min_price = min(prices[i], min_price)
            ans = max(prices[i]-min_price, i)
            dfs(prices,i+1)

        dfs(prices, 0)
        return ans

    #5. 动态规划
    def maxProfit4(self, prices: List[int]) -> int:
        '''
        条件 1：你不能在买入股票前卖出股票；
        条件 2：最多只允许完成一笔交易。
        dp[i][0]表示当天 不持股的收益， dp[i][1] 表示当天持股的收益
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
        dp[i][1] = max(-prices[i], dp[i-1][1])      -prices[i]表示股票只能买卖一次
        dp[i][1] = -prices[0]
        :param prices:
        :return:
        '''
        n = len(prices)
        dp = [[0] * 2] * n
        # dp = [[0 for i in range(2)] for j in range(n)]

        print(dp)
        dp[0][1] = -prices[0]
        for i in range(1, n):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])          #未持有
            dp[i][1] = max(-prices[i], dp[i - 1][1])                        #持有
        return dp[n - 1][0]

    #5. 动态规划空间优化
    def maxProfit4(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [0] * 2
        dp[0] = 0
        dp[1] = -prices[0]

        for i in range(1,n):
            dp[0] = max(dp[1]+prices[i], dp[0])
            dp[1] = max(dp[1], -prices[i])
        return dp[0]