
'''
三数之和：
    思想: 排序 + 双指针
         遍历， 双指针过程中需要跳过相同的数
'''

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        n = len(nums)
        ans = []
        for i in range(n):
            #细节1，相邻两个相同的数字，跳过
            if i > 0 and nums[i] == nums[i-1]:
                continue
            if nums[i] > 0:
                break
            j = i+1
            k = n-1
            t = -nums[i]
            while j < k:
                if nums[j] + nums[k] == t:
                    ans.append([nums[i], nums[j], nums[k]])
                    #细节2，相邻两个相同的数字，跳过，组成的三元组会重复
                    while j < k and nums[j] == nums[j+1]:
                        j += 1
                    while j < k and nums[k] == nums[k-1]:
                        k -= 1
                    k -= 1
                    j += 1
                elif nums[j] + nums[k] > t:
                    k -= 1
                elif nums[j] + nums[k] < t:
                    j += 1
        return ans
'''
[-1,0,1,2,-1,-4]
[-4,-1,-1,0,1,2]

[1,-1,-1,0]
[-1,-1,0,1]

'''