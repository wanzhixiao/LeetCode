import heapq

'''
滑动窗口最大值
    堆中存放 (数字，下标），使用大顶堆
    当i - 堆顶元素下标 >= k, 说明要把最大值pop出去
    每次遍历时将堆顶元素加入结果数组 
'''

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = []
        for i in range(k):
            # python默认是小顶堆，加符号变成大顶堆，取堆堆顶元素时再添加符号
            q.append((-nums[i],i))
        heapq.heapify(q)
        ans = [-q[0][0]]
        n = len(nums)
        for i in range(k,n):
            heapq.heappush(q,(-nums[i],i))
            while i - q[0][1] >= k:
                heapq.heappop(q)
            ans.append(-q[0][0])
        return ans