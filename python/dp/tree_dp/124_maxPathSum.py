

'''
二叉树的最大路径和
    后序遍历，
    父节点需要指导子树中哪边的路径和更大，max(lsum,rsum) + root.val
    在向上归的过程中，更新ans = max(ans, lsum+rsum+root.val)
    注意，rsum,lsum 需要大于0， 否则向上返回时会使得路径和更小

    原问题：
    从根节点到叶子节点中，路径的最大和
    自底向上（后序遍历）递推解法，由子问题（叶子节点）推导出原问题
    自顶向下（前序遍历）递归解法，由原问题（根节点）往下求解问题，递归的结束条件一般是到遇到空节点（叶子节点下的空节点）
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -inf
        def dfs(root):
            if root is None:
                return 0
            nonlocal ans
            lsum = dfs(root.left)
            rsum = dfs(root.right)
            lsum = lsum if lsum > 0 else 0
            rsum = rsum if rsum > 0 else 0
            #更新遍历过程中最大的路径长度
            ans = max(ans, lsum+rsum+root.val)
            #只能向上返回一侧的路径， 父节点需要子节点中的最大的路径和
            return max(lsum, rsum) + root.val
        dfs(root)
        return ans