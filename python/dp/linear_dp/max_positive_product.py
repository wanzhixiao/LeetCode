

import sys

'''
1 -2 -3
1 2 3
-1 2 3 4

1 2 3 -5 1


'''

n = input()
arr = list(map(int, input().split()))

def max_subarray_product(arr):
    n = len(arr)
    pt = [0]*n
    nt = [0]*n
    pt[0] = 1 if arr[0] > 0 else 0
    nt[0] = 1 if arr[0] < 0 else 0
    ans = 0
    for i in range(1, n):
        val = arr[i]
        if val > 0:
            pt[i] = pt[i-1] + 1
            nt[i] = nt[i-1] + 1 if nt[i-1] > 0 else 0
        elif val < 0:
            nt[i] = pt[i-1] + 1
            pt[i] = nt[i-1] + 1 if nt[i-1] > 0 else 0
        else:
            pt[i] = 0
            nt[i] = 0
        ans = max(ans,pt[i])
    return ans

print(max_subarray_product(arr))