
'''
青蛙跳台阶，每次可以跳一阶或者二阶，问跳到第n阶有多少种跳法
思路： 求斐波那契数列
'''
def fn(n):
    if n <= 1:
        return 1
    dp = [0 for _ in range(n+1)]
    dp[0] = 1
    dp[1] = 1
    dp[2] = 2
    for i in range(3,n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]

def fn2(n):
    if n <= 1:
        return 1
    dp = [0 for _ in range(n+1)]
    dp[0] = 1
    dp[1] = 1
    for i in range(0,n-1):
        dp[i+2] = dp[i] + dp[i+1]
    return dp[n]


#dp空间优化
def fn4(n):
    f1,f2 = 1,1
    for i in range(2,n+1):
        f1, f2 = f2, f1+f2
    return f2

@cache
def fn5(n):
    if n <= 1:
        return 1
    return fn5(n-1) + fn5(n-2)

if __name__ == '__main__':
    n = int(input())
    print(fn(n))
