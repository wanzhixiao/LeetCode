
'''
丑数
题意：只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
例如:
    输入 n = 10
    输出 1, 2, 3, 4, 5, 6, 8, 9, 10, 12，是前10个丑数
思路：
    因为每个数都是由2,3,5三个质数的倍数，因此，可以维护三个指针变量，每次选择2,3,5中最小的数对应的倍数作为下一个丑数
    p2  0   1  2   3
    p3  0   0  1   1
    p5  0   0  0   0
    slx p2  p2 p3 p2
    num 1  2  3   4

    dp[i] 表示第i个丑数
    dp[i] = min(dp[p2]*2, dp[p3]*3, dp[p5]*5)
    初始化
    dp[0] = 1 第一个丑数， p2 = p3 = p5 = 0

细节：
    丑数重复，在选最小的时候需要更新指针
    如 2*5, 5*2， 此时p2 = 1, p5 = 1

1, 2, 3, 4, 5, 6, 8, 9, 10, 12
f(6) = 6 f(2)*3 或者f(3)*2
f(7) = 8 = f(4)*2
f(8) = 9 = f(3)*3
f(9) = 10 = f(5)*2

f(i) = min(f(p2)*2, f(p3)*3, f(p5)*5)
for i in range(2,n+1):
    # 遍历之前所有的丑数， 大于前一项且乘以2或3或5的结果最小的，就是f(i)
    res = inf
    for j in range(i):
        if f[j]*2 > f[i-1]:
            res = min(res, f[i]*2)
        if f[i]*3 > f[i-1]:
            res = min(res, f[i]*3)
        if f[i]*5 > f[i-1]:
            res = min(res, f[i]*5)
    f[i] = res
时间复杂度 O(n^2), 每次寻找下一个丑数都要遍历之前的丑数


思路2： bfs+最小堆
最小堆的性质，根节点<左孩子，根节点<右孩子
 bfs 取堆顶元素m, 试探2*m, 3*m, 5*m是否在vis数组中，不在则加入堆和vis数组中， vis表示s试探的数已经被范围
 step记录当前遍历的是第几个丑数

'''
import heapq

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        p2,p3,p5 = 0,0,0
        dp = [1 for _ in range(n+1)]
        dp[0] = 1
        for i in range(1,n):
            m = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5))
            dp[i] = m
            if m == dp[p2]*2:
                p2 += 1
            if m == dp[p3]*3:
                p3 += 1
            if m == dp[p5]*5:
                p5 += 1

        return dp[n-1]

    def nthUglyNumber2(self, n: int) -> int:
        h = [1]
        vis = {1}
        step, res = 1, 1
        while len(h):
            res = heapq.heappop(h)
            if step == n:
                break
            for x in [2*res,3*res,5*res]:
                if x in vis:
                    continue
                heapq.heappush(h,x)
                vis.add(x)
            step += 1
        return res