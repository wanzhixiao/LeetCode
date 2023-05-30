
N = 1002
tr = [[] for _ in range(N)]
f = [[0]*2 for _ in range(N)]
v = [0 for _ in range(N)]
Happy = [0 for _ in range(N)]

def dfs(u,fa):
    #选或不选的收益
    f[u][0] = 0
    f[u][1] = Happy[u]
    #遍历u的邻居
    for x in tr[u]:
        #如果父节点未被访问
        if x == fa:
            continue
        #遍历u的邻居
        dfs(x)
        #不选u, 则u的邻居节点表示为选或者不选中的最大的
        f[u][0] += max(f[x][0], f[x][1])
        #选u, u的邻居为不选
        f[u][1] += f[x][0]
    return

n = int(input())
for i in range(n):
    Happy[i] = int(input())
for i in range(n):
    x,y = map(int,input().split())
    v[x] = 1
    tr[y].append(x)
    tr[x].append(y)

root = 0
for i in range(n):
    if v[i] == 0:
        root = i
        break
print(root)
dfs(root)
print(max(f[root][0],f[root][1]))