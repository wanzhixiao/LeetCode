# 二维转一维搜索

class Solution:
    #时间复杂度 O(logm+logn) = O(logmn)
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        l = 0
        r = m*n-1

        while l <= r:
            mid = l + (r-l)//2
            if matrix[mid//n][mid%n] == target:
                return True
            elif matrix[mid//n][mid%n] < target:
                l = mid + 1
            elif matrix[mid//n][mid%n] > target:
                r = mid - 1
        return False

    #从左下角开始搜索，时间复杂度 O(m+n)
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        i, j = m - 1, 0

        while i >= 0 and j < n:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                i -= 1
            else:
                j += 1
        return False