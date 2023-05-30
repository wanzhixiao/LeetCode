'''
最小花费爬楼梯
每次跳一步或者跳两步，代价是所处台阶的花费
思路：类似斐波那契数列

'''

def min_cost_climb_stairs(cost):
    n = len(cost)
    if n <= 1:
        return 0

    for i in range(2 ,n):
        cost[i] = min(cost[ i -1], cost[ i -2]) + cost[i]
    return min(cost[ n -1] ,cost[ n -2])

n = int(input())
arr = list(map(int, input().split()))
ans = min_cost_climb_stairs(arr)
print(ans)