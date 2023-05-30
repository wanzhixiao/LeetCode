'''
合并区间
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
    思路：
        区间1 [s1,e1],[s2,e2]能够合并的前提是e1>=s2，合并后的结果[s1,e2]，否则合并之后还是[s1,e1], [s2,e2]
    我们需要使用贪心的思路，将区间起点小的s尽可能排在前面，

#时间复杂度
    瓶颈在排序部分O(nlog(n))
'''

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        # True表示降序， False为升序
        intervals = sorted(intervals,key=lambda x:x[0],reverse=False)
        #第二种排序 intervals.sort(key=lambda x: x[0])
        ans = [intervals[0]]
        n = len(intervals)
        for i in range(1,n):
            x = intervals[i]
            if ans[-1][1] >= x[0]:
                ans[-1][1] = ans[-1][1] if ans[-1][1]>x[1] else x[1]
            else:
                ans.append(x)
        return ans
