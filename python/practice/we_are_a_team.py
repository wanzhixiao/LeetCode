


class unionFind(object):

    def __init__(self, n):
        self.root = [0]*(n+1)
        self.cnt = [1]*(n+1)
        for i in range(n+1):
            self.root[i] = i

    def find(self, x):
        #隔代路径压缩
        while x != self.root[x]:
            self.root[x] = self.root[self.root[x]]
            x = self.root[x]
        return self.root[x]

        # 彻底路径压缩
        # if x != self.root[x]:
        #     self.root[x] = self.find(self.root[x])
        # return self.root[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX == rootY:
            return

        if self.cnt[rootX] > self.cnt[rootY]:
            self.root[rootY] = rootX
            self.cnt[rootX] += self.cnt[rootY]
        else:
            self.root[rootX] = rootY
            self.cnt[rootY] += self.cnt[rootX]
        return

    def isConected(self, x, y):
        return self.find(x) == self.find(y)


def judge():
    n, m = map(int, input().split())
    uObj = unionFind(n)

    while m > 0:
        a,b,c = map(int, input().split())
        m -= 1
        if (a>n or a < 1) or (b > n or b < 1) or (c != 0 and c != 1):
            print("da pian zhi")
            continue
        if c == 0:
            uObj.union(a,b)
        else:
            if uObj.isConected(a, b):
                print("we are a team")
            else:
                print("we are not a team")

judge()

'''
5 7
1 2 0
4 5 0
2 3 0
1 2 1
2 3 1
4 5 1
1 5 1

5 6
1 2 0
1 2 1
1 5 0
2 3 1
2 5 1
1 3 2
'''