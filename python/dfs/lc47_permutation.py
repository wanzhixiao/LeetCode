

ans = []
def permute(nums):
    nums.sort()
    n = len(nums)
    used = [False for _ in range(n)]
    path = []
    dfs(nums, 0, n, used, path)

def dfs(nums, j, n, used, path):
    #到达叶子节点则返回
    if j == n:
        ans.append(path.copy())
        return
    #横向枚举下一个数
    for i in range(n):
        if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
            continue
        #第i个数未被使用
        if not used[i]:
            used[i] = True
            #纵向进入下一层 j+1
            dfs(nums, j+1, n, used, path+[nums[i]])
            used[i] = False

nums = [1,2,3]
permute(nums)
print(ans)

'''                                  []
 
                           /           \           \
                          1             2           3
                         / \           / \         / \
                        1,2 1,3       2,1 2,3    3,1 3,2
                      /     \         /    \      /    \
                     1,2,3  1,3,2   2,1,3  2,3,1 3,1,2  3,2,1

'''
