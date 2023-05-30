

'''
股票最大利润
思路1： 遍历，找出最小的股票价格
    当前价格-最小股票价格 的最大值
思路2： 动态规划，也可以分为手上持有和未持有两种状态求解
    dp[i][0]表示当天 不持股的收益， dp[i][1] 表示当天持股的收益
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
    dp[i][1] = max(-prices[i], dp[i-1][1])      -prices[i]表示股票只能买卖一次

    未持有的收益 = max(第i-1天未持有的收益，第i-1天持有 + prices[i](第i天卖出))
    持有的收益 = max(第i-1天持有的收益，第i-1天买入）
    # 初始化，第0天手上持有的收益
    dp[0][1] = -prices[0]
'''

def maxProfit(self, prices: List[int]) -> int:
    n = len(prices)
    if n <= 1:
        return 0
    minprice = prices[0]
    ans = 0
    for i in range(1 ,n):
        if prices[i] < minprice:
            minprice = prices[i]
        ans = max(ans, prices[i ] -minprice)
    return ans