
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# lc 112
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        #空节点
        if root is None:
            return False
        # 判断当前节点是否为根节点
        if not root.left and not root.right:
            return targetSum == 0
        l, r = False, False
        if root.left:
            l = self.hasPathSum(root.left, targetSum - root.val)
        if root.right:
            r = self.hasPathSum(root.right,targetSum - root.val)
        return l or r


# lc 113
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if root is None:
            return []
        ans = []
        def dfs(root,path):
            #空节点
            if root is None:
                return
            #叶子节点
            if root.left is None and root.right is None:
                if sum(path) == targetSum:
                    ans.append(path.copy())
                return
            #横向尝试
            if root.left:
                path.append(root.left.val)
                # 纵向探索
                dfs(root.left, path)
                path.pop()
            if root.right:
                path.append(root.right.val)
                dfs(root.right, path)
                path.pop()
            return

        path = [root.val]
        dfs(root, path)
        return ans