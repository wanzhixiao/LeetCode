

#二叉搜索树中第K小的元素
# 方法，中序遍历， 左-根-右
class Solution:
    #非递归解法
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        ans = 0
        def traverse(root):
            if not root:
                return
            q = [root]
            while len(q):
                rt = q.pop()
                if rt:
                    if rt.right:
                        q.append(rt.right)
                    q.append(rt)
                    q.append(None)
                    if rt.left:
                        q.append(rt.left)
                else:
                    rt = q.pop()
                    nonlocal ans, k
                    k -= 1
                    if k == 0:
                        ans = rt.val
                        break
        traverse(root)
        return ans

    #递归解法
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        ans = 0
        def dfs(root):
            nonlocal ans, k
            if root is None or k <= 0:
                return
            dfs(root.left)
            k -= 1
            if k == 0:
                nonlocal ans
                ans = root.val
            dfs(root.right)
        dfs(root)

        return ans