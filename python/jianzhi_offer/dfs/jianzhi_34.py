

# 剑指 Offer 34. 二叉树中和为某一值的路径

'''
思路： 回溯法
    维护一个path数组，和pathsum
    每向下遍历一个节点时，进行如下操作
        path.append(root.val)
        pathsum += root.val
        #递归左右子树
        dfs(root.left, path, psum)
        dfs(root.right, path, psum)
        #回到上一层
        path.pop()
        pathsum -= root.val
'''

class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:

        ans = []
        def dfs(root, path, psum):
            if root is None:
                return
            path.append(root.val)
            psum += root.val
            if root.left is None and root.right is None and psum == target:
                ans.append(path.copy())
            dfs(root.left, path, psum)
            dfs(root.right, path, psum)
            psum -= root.val
            path.pop()
        dfs(root, [], 0)
        return ans