

'''
输入节点个数，输出二叉搜索树种数
分析：
    左子树节点个数能够组成的bst种树 + 右子树能够组成的bst种树
    假设树种一共有n个节点， 左子树节点编号为1...j-1（一共j-1个节点）, j为根节点，j+1,...,i为右子树（一共i-j个节点）
    1 2 3 4 5
    定义: dp[i]表示树中节点i个数为i时的树的种树
    dp[i] = dp[0]*dp[i] + dp[1]*dp[i-1] + dp[j-1] * dp[i-j]
    初始化：
    dp[0] = 1
    dp[1] = 1
    递推
        for i in range(2,n+1):
            for j in range(1,i+1):
'''

def num_tree(n):
    dp = [0 for _ in range(n+1)]
    dp[0] = 1
    dp[1] = 1
    for i in range(2,n+1):
        # for j in range(0,i):
        #     dp[i] += dp[j] * dp[i-j-1]      #左子树种数 * 右子树种树
        for j in range(1,i+1):
            dp[i] += dp[j-1] * dp[i-j]

    return dp[n]

n = int(input())
print(num_tree(n))