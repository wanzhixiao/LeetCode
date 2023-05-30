
'''
221 最大正方形
    正方形的面积 = 边长*边长
    本题等价于求最长的正方形边长是多少
当matrix[i][j] == '1'时， 考虑以下几种情况，看边长是否能够由于当前1的加入变得更长
1.
    1 1
    1 1
2.
    1 1
    0 1
3.  1 0
    1 1
4.  0 1
    1 1
1是可以的2和3,4的边长中都有一个0, 加上当前数边长不能变得更长
dp[i][j]表示以i,j结尾的边长的长度，那么，dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])

5. x x
   x 0
x为0或者1
如果matrix[i][j]=='0', 那么无论matrix[i-1][j], matrix[i][j-1], matrix[i-1][j]为何数时，加上matrix[i][j]边长都不会变得
更长
    因此 dp[i][j] = 0

在求解最长边长的过程中需要更新最长的边长，ans = max(ans,dp[i][j])
'''
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m, n = len(matrix), len(matrix[0])
        dp = [[0 ] *n for _ in range(m)]
        ans = 0
        for i in range(m):
            d = 1 if matrix[i][0] == '1' else 0
            dp[i][0] = d
            ans = max(d ,ans)

        for i in range(n):
            d = 1 if matrix[0][i] == '1' else 0
            dp[0][i] = d
            ans = max(d ,ans)
        for i in range(1 ,m):
            for j in range(1 ,n):
                if matrix[i][j] == '1':
                    dp[i][j] = 1 + min(dp[ i -1][j] ,min(dp[ i -1][j -1] ,dp[i][ j -1]))
                else:
                    dp[i][j] = 0
                ans = max(dp[i][j] ,ans)

        return ans *ans
