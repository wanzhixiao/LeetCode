'''
题意： 下一个排列
思路： 把左侧较大的数与右侧较小的数互换位置， 找到第一个升序的位置k, 如果k=0, 则需要整个反转数组，如3,2,1， k = 0, 反转后数组1,2,3
    2 1 3 如何反转？
    找到第一个升序的位置 1 3， k = 2
    再找到k-1右侧第一个 比nums[k-1]大的数nums[n], 交换nums[k-1]和nums[n]
    2 1 3-> 2 3 1


1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

1 2 3 4
1 2 4 3
'''

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = len(nums)-1
        while k > 0 and nums[k] <= nums[k-1]:
            k -= 1
        if k == 0:  # 3 2 1
            n = len(nums)
            nums = nums.reverse()
            return
        else:
            n = len(nums)-1
            while nums[n] <= nums[k-1]:
                n -= 1
            t = nums[n]
            nums[n] = nums[k-1]
            nums[k-1] = t

            #这里可以利用切片
            n = len(nums)-1
            while k < n:
                t = nums[n]
                nums[n] = nums[k]
                nums[k] = t
                k += 1
                n -= 1
        return


