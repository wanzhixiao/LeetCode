

'''
题目：
通知所有员工所需的最短时间
               2
         / \ \ \ \ \ \
        0  1 2 3 4 5 6

题目转化
给定一棵多叉树，将树上的所有节点的值进行求和

'''

class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:

        n = len(manager)
        def dfs1(i):
            # 根节点
            if informTime[i] == 0:
                return 0
            t = 0
            # 遍历一棵多叉树,i是父亲节点
            for j, x in enumerate(manager):
                # 如果j的父亲节点为i
                if x == i and informTime[j] != 0:
                    # print(j, informTime[j])
                    # 继续递归j
                    t = max(t ,dfs1(j))
            return t + informTime[i]
        return dfs1(headID)
# 时间复杂度，O(n) * 树的最大深度， 对于每一层，都需要遍历manager数组找子节点

    #后序遍历， 递归
    def numOfMinutes2(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        n = len(manager)
        g = [[] for _ in range(n)]
        for i,x in enumerate(manager):
            if x != -1:
                g[x].append(i)

        def dfs1(i):
            # 根节点
            if informTime[i] == 0:
                return 0
            t = 0
            # 遍历一棵多叉树,i是父亲节点, x是i的子节点, 找到x的孩子节点中最耗时的一条路径
            for x in g[i]:
                #如果子节点不是叶子节点
                if informTime[x] != 0:
                    # print(j, informTime[j])
                    # 继续递归x(向下）
                    t = max(t ,dfs1(x))
            #向上返回
            return t + informTime[i]
        return dfs1(headID)

    '''
    # 往下递
    l = dfs(root.left)
    r = dfs(root.right)
    # 往上归
    return max(l,r) + 1
    '''

    # 往下递
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        # 建树，自上而下
        n = len(manager)
        g = [[] for _ in range(n)]
        for i, x in enumerate(manager):
            if x != -1:
                g[x].append(i)
        ans = 0
        def dfs1(i, cost):
            # 根节点
            if informTime[i] == 0:
                return
            cost += informTime[i]
            nonlocal ans
            ans = max(ans, cost)
            for x in g[i]:
                dfs1(x, cost)

        dfs1(headID, 0)

        return ans

'''
    先序遍历：
        访问 root, 从上往下更新答案变量
        dfs(root.left)
        dfs(root.right)
'''