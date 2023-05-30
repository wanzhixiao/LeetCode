
def binary_search(arr, target):
    if len(arr) > target:
        return -1
    l, r = min(fileds)-1, max(fileds)+1

    while l + 1 < r:
        mid = l + (r-l)//2
        if check(arr, mid, target):
            r = mid
        else:
            l = mid
    return -1 if r == max(fileds) + 1 else r

def check(arr, mid, target):
    cnt = 0
    for x in arr:
        cnt += (x//mid + 1 if x%mid > 0 else 0)
        if cnt > target:
            return False
    return True


m,n = list(map(int,input().split()))
fileds = list(map(int, input().split()))

ans = binary_search(fileds,n)
print(ans)








