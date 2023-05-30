

'''
礼物最大价值
    从左上到右下，每次向下或者向右，求路径的最大和
    思路1： 记忆化递归，从右下角开始递归到左上角
    思路2： 递推，从左上角递推到右下角
    思路3： 广度优先遍历+priority_queue, 每次将下一步（左侧或者下方最大和的坐标进行探测，先探测到终点的路径即为答案）
'''

class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        @cache
        def dfs(i,j):
            if i < 0 or j < 0:
                return 0
            if i == 0 and j == 0:
                return grid[0][0]
            elif i == 0:
                return dfs(i,j-1) + grid[i][j]
            elif j == 0:
                return dfs(i-1, j) + grid[i][j]
            return max(dfs(i-1,j),dfs(i,j-1)) + grid[i][j]
        ans = dfs(m-1,n-1)
        return ans