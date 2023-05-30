


'''
使得数组递增
输入：arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
输出：1
解释：用 2 来替换 5，之后 arr1 = [1, 2, 3, 6, 7]
'''
import sys
from bisect import bisect_right
from functools import cache
from typing import List


def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
    arr2.sort()

    @cache
    def dfs(i1, i2, n1, n2, x):
        if i1 == n1:
            return 0
        i2 = bisect_right(arr2, x, lo=i2)
        r1, r2 = 3000, 3000

        # 替换arr1[i], arr1[i]变成arr2[i2](选）
        if (i2 < n2):
            r2 = 1 + dfs(i1 + 1, i2 + 1, n1, n2, arr2[i2])
        # 不替换arr1[i](不选）
        if (x < arr1[i1]):
            r1 = dfs(i1 + 1, i2, n1, n2, arr1[i1])
        return min(r1, r2)

    i1, i2 = 0, 0
    n1, n2 = len(arr1), len(arr2)
    res = dfs(i1, i2, n1, n2, -sys.maxsize)
    return -1 if res == 3000 else res

def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:

    n1, n2 = len(arr1), len(arr2)
    dp = [[0]*3000 for _ in range(3000)]
    prev = -sys.maxsize

    for i1 in range(0,n1):
        r1, r2 = 3000, 300
        i2 = bisect_right(arr2, prev)
        if i2 < n2:
            r1 = 1 + dp[i1]

arr1 = [1,5,3,6,7]
arr2 = [1,3,2,4]
print(makeArrayIncreasing())