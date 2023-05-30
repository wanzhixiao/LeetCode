
'''
子数组最大和
[-2,-1]  -> -1
[-2,1,-3,4,-1,2,1,-5,4] -> 6
方法1： 滑动窗口
    窗口代表什么： 最大和的子数组
    何时移动右指针： 当窗口内的和s > 0
    何时移动左指针：当l<=r 且 s <= 0时
思路2：
    动态规划
    定义子问题： dp[i]表示以第i个数结尾的子数组的最大和是多少
    状态转移： dp[i] = max(dp[i-1] + nums[i], nums[i]
            更新答案 ans = max(ans, dp[i])
    初始化 dp[0] = nums[0]
'''
def maxSubArray(self, nums: List[int]) -> int:
    n = len(nums)
    b = max(nums)
    if b <= 0:
        return b
    ans = b
    l, r = 0 ,0
    s = 0
    while r < n:
        s += nums[r]
        while l <= r and s <= 0:
            s -= nums[l]
            l += 1
        ans = max(ans, s)
        r += 1
    return ans

# 动态规划
def maxSubArray(self, nums: List[int]) -> int:
    n = len(nums)
    dp = [0 for _ in range(n+1)]
    ans = nums[0]
    for i in range(n):
        dp[i+1] = max(dp[i]+nums[i],nums[i])
        ans = max(ans, dp[i+1])
    return ans

# 动态规划空间优化版本， 由于dp[i+1]只跟dp[i]有关，因此可以将dp[i]简化成一个遍历f,使用f对f进行更新
# new f <- old f
def maxSubArray(self, nums: List[int]) -> int:
    n = len(nums)
    f = 0
    ans = nums[0]
    for i in range(n):
        f = f+nums[i]
        f = max(f,nums[i])
        ans = max(ans, f)
    return ans
