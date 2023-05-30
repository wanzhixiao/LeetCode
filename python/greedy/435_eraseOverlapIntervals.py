
'''
435 无重叠区间
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

n表示所有区间数，cnt表示合并后区间的数量，n-cnt就是不重叠区间的数量
将intervals按照右端点进行排序，从左往右遍历，片段end是否<=intervals[i][0]，是则重叠，合并（end=intervals[i][1]),
'''

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # 按照右端点进行排序？ 为什么按照右端点？ 贪心地选择下一个重叠的区间，有边界最小
        intervals.sort(key=lambda x:x[1])
        ans , n = 1, len(intervals)
        end = intervals[0][1]
        for i in range(1,n):
            x = intervals[i]
            if end <= x[0]:
                ans += 1
                end = x[1]
        #返回重叠的数目 = 总数-合并后不重叠的区间数量
        return n-ans


'''
452. 用最少数量的箭引爆气球
 区间贪心问题：给定n个闭区间[x,y]，问最少需要确定多少个点，使得每个闭区间中都至少存在一个点。
 [[1,2],[2,3],[3,4],[4,5]]
 ans = 1
 end = 2
 [2,3]   2 不满足 > end = 2
 [3,4]   3 满足 > end = 2  ans += 1 不重叠区间, 更新end=4
 [4,5]   4 不满足  > end = 2 ,
'''

def findMinArrowShots(self, points: List[List[int]]) -> int:
    points.sort(key=lambda x: x[1])
    ans = 1
    n = len(points)
    end = points[0][1]
    for i in range(1, n):
        x = points[i][0]
        # x > end 表示区间不重叠，需要重新开一支箭
        if x > end:
            end = points[i][1]
            ans += 1
    # 返回可以合并的区间的数量
    return ans


# 57 插入区间
'''
给你一个 无重叠的 ，按照区间起始端点排序的区间列表， 将新的区间插入到intervals中，使合并后的区间不能有重叠
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]

思路1：
    将新区间加入到intervals中，按起点排序，再做区间合并
思路2：
    三段式
    newIntervals[0]和intervals[i][1]
        1.如果 intervals[i][1] < newIntervals[0], 则不断把intervals[i]加到ans
        2.否则， newIntervals[1] >= intervals[i][0]
            比较newIntervals[0]和intervals[i][0]的大小，更新
        将newIntervals加入到ans中
        3.将intervals剩余的区间加入到ans中
'''

def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    ans = []
    n = len(intervals)
    k = 0
    while k < n and intervals[k][1] < newInterval[0]:
        ans.append(intervals[k])
        k += 1
    while k < n and intervals[k][0] <= newInterval[1]:
        newInterval[0] = min(intervals[k][0], newInterval[0])
        newInterval[1] = max(intervals[k][1], newInterval[1])
        k += 1
    ans.append(newInterval)
    while k < n:
        ans.append(intervals[k])
        k += 1
    return ans