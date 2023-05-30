
'''
青蛙跳台阶，每次可以跳1,2,3,...n阶
f(n)=f(n-1)+f(n-2)+……+f(2)+f(1)
f(n-1) = f(n-2)+……+f(2)+f(1)
f(n) = 2*f(n-1)
'''

def fn(n):
    dp = [1 for _ in range(n+1)]
    for i in range(2, n+1):
        for j in range(1,i):
            dp[i] += dp[j]
    return dp[n]


def fn2(n):
    dp = [1 for _ in range(n + 1)]
    for i in range(2, n + 1):
        dp[i] = 2 * dp[i - 1]
    return dp[n]

def fn3(n):
    cur, pre = 1,1
    for i in range(2, n + 1):
        cur = pre+1
        pre += cur
    return cur

def fn3(n):
    return pow(2,n-1)

n = int(input())
print(fn(n))
