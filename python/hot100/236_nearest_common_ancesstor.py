

'''
二叉树的最近公共祖先

方法：后序遍历
    情况1： p,q 在root的左子树
    情况2: p,q在root的右子树
    情况3： p在root的左子树，q在root的右子树

    递归终止条件
    if root is None or root is p or root is q 三种情况，直接返回root
    l = 递归左子树
    r = 递归右子树
    判断左 右子树是否为空
        返回root          #情况1
    情况2 l is not None and r is None
        return l
    情况3 l is None and r is not None
        return r
'''


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 当root节点是空，或者root==p 或 root == q, 返回root
        if root is None or root is p or root is q:
            return root

        l = self.lowestCommonAncestor(root.left, p, q)
        r = self.lowestCommonAncestor(root.right, p, q)
        if l is not None and r is not None:
            return root
        return l if l is not None else r