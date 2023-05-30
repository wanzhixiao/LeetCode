
'''
矩形最大面积
思路1：
    暴力法
        ans = height[0]
        for i = 0 to n
            for j = i to n
                h = min(height[i...j]
                area = (j-i+1)*h
                ans = max(ans,area)
思路2：
    维护一个单调递增栈，栈内存放数组下标
    当遇到height[i]比height[stk.top()]元素小时，计算矩形面积，并将栈顶进行出栈， 循环计算栈内元素面积
    细节，当元素是递增时，如2,4, 需要在height数组末尾加上-1
'''

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:

        heights.append(-1)
        n = len(heights)
        stk = []
        ans = 0
        for i in range(n):
            while len(stk) > 0 and heights[stk[-1]] >= heights[i]:
                h = heights[stk[-1]]
                stk.pop()
                l = -1 if len(stk) == 0 else stk[-1]
                area = (i-l-1) * h
                ans = max(area, ans)
            stk.append(i)

        return ans

    # 时间复杂度 4 3 2 1, O(n)
    # 1, 2 3 4 -1; O(n^2), 进栈+出栈