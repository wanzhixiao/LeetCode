
'''
连续子数组的最大乘积
3
-3 0 -2
nums[i]     -3  0   -2
cur_min     -3  0  -2
cur_max     -3 0    0
ans         -3 0   0

当前的数可能为正数或者负数

正数最大值 = max(正数 * 正数最大值， 负数 * 负数最小值， 当前数)
负数最小值 = min(正数 * 负数最小值， 负数 * 正数最大值， 当前数)
ans = max(max(正数最大值，负数最小值），ans)

'''

n = int(input())
nums = list(map(int, input().split()))
cur_min, cur_max = 1,1
ans = nums[0]

for i in range(n):
    a, b = cur_min, cur_max
    cur_max = max(max(a*nums[i], b*nums[i]), nums[i])
    cur_min = min(min(a*nums[i], b*nums[i]), nums[i])
    print(cur_min, cur_max)
    ans = max(ans, max(cur_min, cur_max))

print(ans)