
'''
309. 最佳买卖股票时机含冷冻期
约束
1.卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)
2.不能同时参与躲避交易

思考：类似于打家劫舍，偷了前一间房子（前一天卖出）， 后面一间不能偷（后一天不能买入）
    dfs(i,hold) <- max(dfs(i-1,True), dfs(i-2, False) - prices[i])
'''
from functools import cache
from typing import List
from transformer.conf import inf

class Solution:
    #记忆化搜索
    def maxProfit(self, prices: List[int]) -> int:
        @cache
        def dfs(i, hold):
            if i < 0:
                return -inf if hold else 0
            if hold:
                return max(dfs(i - 2, False) - prices[i], dfs(i - 1, True))
            return max(dfs(i - 1, False), dfs(i - 1, True) + prices[i])

        return dfs(len(prices) - 1, False)

    #dp 递推
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        f = [[0]*2 for _ in range(n+2)]
        f[1][1] = -inf                      #f从1开始，表示第一天持有股票
        for i in range(n):
            f[i+2][1] = max(f[i+1][1], f[i][0]-prices[i])
            f[i+2][0] = max(f[i+1][1]+prices[i], f[i+1][0])
        return f[-1][0]

    #dp, 递推
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        f = [[0] * 3 for _ in range(n + 1)]
        f[0][1] = -inf

        for i in range(n):
            f[i + 1][0] = max(f[i][0], f[i][2])              # 冷冻 = max(上一天冷冻，上一天未持有）
            f[i + 1][1] = max(f[i][1], f[i][0] - prices[i])  # 持有 = max(上一天持有，上一天冷冻-prices[i]（买入）)
            f[i + 1][2] = max(f[i][1] + prices[i], f[i][2])  # 未持有 = max(上一天冷冻， 上一天持有+prices[i]（卖出）)

        return max(f[n][0], f[n][2])

    #dp 空间优化
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        f = [0] * 3
        f[1] = -inf

        for i in range(n):
            f[1] = max(f[1], f[0] - prices[i])  # 持有
            f[0] = max(f[0], f[2])  # 冷冻
            f[2] = max(f[1] + prices[i], f[2])  # 未持有

        return max(f[0], f[2])