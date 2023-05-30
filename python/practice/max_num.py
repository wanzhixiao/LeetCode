
def sort_str(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            #比较相邻两个数的大小
            lag = False
            len1, len2 = len(arr[j]), len(arr[j+1])
            p, q = 0, 0
            while p < len1 and q < len2:
                if arr[j][p] == arr[j+1][q]:
                    p += 1
                    q += 1
                elif arr[j][p] < arr[j+1][q]:
                    break
                elif arr[j][p] > arr[j+1][q]:
                    lag = True
                    break
            if lag:
                swap(arr,j,j+1)

            if p < len1 and q == len2:
               swap(arr, j, j+1)
    return arr[-1::-1]

def swap(arr, i, j):
    t = arr[i]
    arr[i] = arr[j]
    arr[j] = t

arr = list(map(str,input().split(',')))
arr1 = sort_str(arr)
ans = ''.join(arr1)
print(ans)



'''
排序规则
s1 + s2 < s2 + s1
例如：
'30'+'3' < '3'+'30'
'''
