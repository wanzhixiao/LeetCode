#第一题
class Solution(object):
    def minNumber(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        nums1.sort()
        nums2.sort()

        a = nums1[0]
        b = nums2[0]

        lena = len(nums1)
        lenb = len(nums2)
        if lena < lenb:
            for item1 in nums1:
                if item1 in nums2:
                    return item1
        else:
            for item1 in nums2:
                if item1 in nums1:
                    return item1
        mx = max(a, b)
        mi = min(a, b)
        return mi * 10 + mx

#第二题
class Solution(object):
    def maximumCostSubstring(self, s, chars, vals):
        """
        :type s: str
        :type chars: str
        :type vals: List[int]
        :rtype: int
        """
        val_dict = {}
        default_dict = {}
        for ch, val in zip(chars, vals):
            val_dict[ch] = val

        for i in range(0, 26):
            default_dict[chr(ord('a') + i)] = i + 1

        nums = [val_dict[ch] if ch in val_dict else default_dict[ch] for ch in s]

        # 最大连续子数组和

        s = 0
        ans = nums[0]

        for num in nums:
            s += num
            s = max(s, num)
            ans = max(s, ans)

        return ans if ans >= 0 else 0

#第三题
class Solution(object):
    def makeSubKSumEqual(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        avg_num = sum(arr) // len(arr) + 1

        min_gap = abs(arr[0] - avg_num)
        idx = 0
        for i in range(k):
            if abs(arr[i] - avg_num) < min_gap:
                min_gap = abs(arr[i] - avg_num)
                idx = i
        print(idx, min_gap)

        return 0

#第四题
class Solution(object):
    def findShortestCycle(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """

        # 构图
        g = [[] for _ in range(n)]
        for edge in edges:
            v1, v2 = edge[0], edge[1]
            g[v1].append(v2)
            g[v2].append(v1)

        # 最长环的长度
        # DFS : 深度优先搜索：思想是，DFS过程，记录当前结点的父结点，如果某结点已经被访问过且不是当前结点的父结点，则存在环
        visited = [False for _ in range(n)]
        for i in range(n):
            if visited[i]:
                continue
            ans = self.dfs(g, i, -1, visited, 0)
            print(ans)

    def dfs(self, g, u, fa, visited, cicle_len):
        if visited[u]:
            return 0
        visited[u] = True

        for v in g[u]:
            if visited[v] and v != fa:
                return cicle_len
            self.dfs(g, v, u, visited, cicle_len + 1)
        return cicle_len

'''
首先，是尽量少找简单题，就算做也要看看答案的好方法；
其次是找一些通过率60％以下的题，尝试自己想，不管是不是自己思考出来，
做完都要把答案里面的其他常规方法自己实现一下。
过了几个月之后再参加的时候发现，
周赛基本可以多数时候ac三题了，
偶尔ak或者只ac两道（当然不排除周赛有相比原来放水的原因??????，
不过自我感觉，相比原来，看到题之后思路来的更快了，也容易写出来）
'''