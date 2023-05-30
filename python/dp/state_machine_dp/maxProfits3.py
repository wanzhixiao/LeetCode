from functools import cache
from math import inf
from typing import List
import sys

'''
最多完成两笔交易
定义dp[i][j][0] 表示第i天第j次交易 未持有股票
dp[i][j][1] 表示第i天第j次(j∈(0,1))交易 持有股票
dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]+prices[i])
dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i])
'''

class Solution:
    def maxProfit1(self, prices: List[int]) -> int:
        n = len(prices)
        # dp = [[[0]*2]*3]*(n+1)
        dp = [[[0 for _ in range(2)] for _ in range(3)] for _ in range(n+1)]
        #第0天发生一次股票后手上持有股票
        dp[0][1][1] = -prices[0]
        #第0天发生两次交易后手上持有股票
        dp[0][2][1] = -sys.maxsize

        for i in range(1,n+1):
                #先持有股再卖出
                dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i-1])
                dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i-1]) #dp[i - 1][j-1][1] + prices[i], 买卖只算一次交易

                dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i-1])
                dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i - 1])

        return max(dp[n][0][0], max(dp[n][1][0], dp[n][2][0]))

    def maxProfit2(self , prices: List[int]) -> int:
        # write code here
        n = len(prices)
        @cache
        def dfs(i, j, hold):
            if j < 0:
                return -inf
            if i < 0:
                return -inf if hold else 0
            if hold:
                return max(dfs(i-1, j, True), dfs(i-1, j-1, False)-prices[i])
            return max(dfs(i-1, j, False), dfs(i-1, j, True)+prices[i])
        return dfs(n-1, 2, False)

    def maxProfit3(self, prices: List[int]) -> int:
        n = len(prices)
        # 这里为什么是k+2, 因为有[0,1,2,3], 最多两笔交易，可以是0次，1次，2次， 对应下标1,2,3
        dp = [[[-inf] * 2 for _ in range(4)] for _ in range(n + 1)]

        for i in range(1, 4):
            dp[0][i][0] = 0

        for i in range(n):
            for j in range(1, 4):
                # 使用 dp[i+1] <- dp[i] 防止越界
                dp[i + 1][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - prices[i])
                dp[i + 1][j][0] = max(dp[i][j][0], dp[i][j][1] + prices[i])

        return dp[n][3][0]


if __name__ == '__main__':
    s = Solution()
    prices = [3,3,5,0,0,3,1,4]
    ans1 = s.maxProfit1(prices)
    ans2 = s.maxProfit2(prices)
    ans3 = s.maxProfit3(prices)
    print(ans1, ans2, ans3)

    # assert s.maxProfit(prices) == 6
