
'''
验证二叉搜索树
思路1： 先序遍历， 使用lower,upper两个变量
    lower < root.val < upper and dfs(root.left, lower, root.val) and dfs(root.right, root.val, upper)
思路2： 中序遍历
    记录一个pre节点
    dfs(root.left)
    if pre >= root.val: return False
    pre = root.val
    dfs(root.right)
'''
class Solution:
    def isValidBST1(self, root: Optional[TreeNode]) -> bool:
        # 先序遍历
        def dfs(root, lower, upper):
            if root is None:
                return True
            if root.val <= lower or root.val >= upper:
                return False
            return dfs(root.left, lower, root.val) and dfs(root.right, root.val, upper)

        return dfs(root, -sys.maxsize, sys.maxsize)

    def isValidBST2(self, root: Optional[TreeNode]) -> bool:
        pre = None
        def dfs(root):
            nonlocal pre
            if root is None:
                return True;
            left = dfs(root.left)
            if pre is not None and pre.val >= root.val:
                return False
            pre = root
            right = dfs(root.right)
            return left and right
        return dfs(root)

    def isValidBST3(self, root: Optional[TreeNode]) -> bool:
        pre = -inf
        def dfs(root):
            if root is None:
                return True
            if not dfs(root.left):
                return False
            if root.val <= pre:
                return False
            pre = root.val
            return  dfs(root.right)
        return dfs(root)