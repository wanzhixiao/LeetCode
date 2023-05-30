
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:

        ans = []
        st = set()
        def dfs(root, path ,d):
            nonlocal ans ,st
            if root is None:
                return
            path = str(root.val) if len(path )==0 else path + '_' + str(root.val ) +'_ ' +d
            # print(path)
            if path in st:
                a = path.split('_')[:-1]
                b = list(map(int ,a))
                print(path ,len(path))

            st.add(path)

            # if path in st:
            #     a = path.split('_')
            #     b = list(map(int,a))
            #     ans.append(b)
            #     print(b)
            # st.add(path)
            dfs(root.left, path ,'l')
            dfs(root.right, path ,'r')

        def dfs2(root):
            if root is None:
                return
            path = ''
            dfs(root ,path ,'f')
            dfs2(root.left)
            dfs2(root.right)

        dfs2(root)
        # return ans
        return []


    '''
    相似的子结构：
        使用后序遍历
        向上返回的是子树的结构，
        当前结构 = 父节点 + 左子树结构 + 右子树结构
        如果当前结构在 哈希表中出现过两次（首次）， 则说明在树中找到了相似的结构，将root（当前节点及其子树）加入到结果集中
        
        向上返回的是当前树及子树的结构
    '''

    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        ans = []
        dic = {}
        def dfs(root):
            nonlocal ans,dic
            if root is None:
                return '#'
            #后序遍历
            key = str(root.val) + '_'
            key += dfs(root.left)
            key += dfs(root.right)
            if key in dic:
                dic[key] += 1
            else:
                dic[key] = 1
            #首次判定为重复出现
            if dic[key] == 2:
                ans.append(root)
            print(key)
            return key
        dfs(root)
        return ans

    '''
    后序遍历模板
    def dfs(root):
        if root is None:
            return
        #从当前节点开始累积结果
        ans = 0
        l = dfs(root.left)
        r = dfs(root.right)
        a = l+r+root.val
        b = max(l,r)+root.val
        c = min(l,r)+root.val
        #更新全局的ans变量
        nonlocal ans
        ans = max(a,c)
        #向上一层返回当层的结果
        return a or b or c
    ans
    dfs(root)
    '''
