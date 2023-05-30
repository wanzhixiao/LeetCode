'''
51. 数组中的逆序对数
求逆序数对发生在归并的并的过程中，左侧和右侧分别是有序的；此时只需比较归并的左右两个数p,q大小
1. 若p < q; 无逆序
2. 若p > q; 产生逆序， 且逆序对数为mid-p+1
举个例子
nums = [7 5 6 4]

                 7 5 | 6 4
    归          /  \    / \
               7    5  6   4
                \ /     \ /
    并          5 7     4 6
                  \    /
                 4 5 6 7

在第一次并的过程中，
    左侧数组 L = [7], R=[5]; 产生逆序对（7,5）； mid-p+1 = 0-0+1 = 1
    右侧数组 L = [6], R=[4]; 产生逆序对（6,4）； mid-p+1 = 2-2+1 = 1
在第二次并的过程中
    左侧数组L = [5,7], 右侧数组 R = [4,6]；整个数组长度为4，令
    p = 0, q = 2, mid = 1, r = 3；
    由于nums[p] = 5 > nums[q] = 4，5和4之间的逆序对数为 mid - p + 1 = 1 - 0 + 1 = 2; 逆序对为(5,4),(7,4)
    同样： 7和6之间的产生逆序对(7,6), 逆序数对mid-p+1 = 1-1+1 = 1
总逆序数对 = 1 + 1 + 2 + 1 = 5
'''

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        ans = 0

        def mergeSort(nums, l, r):
            if l >= r:
                return
            mid = (l + r) >> 1
            mergeSort(nums, l, mid)
            mergeSort(nums, mid + 1, r)
            merge(nums, l, mid, r)

        def merge(nums, l, mid, r):
            nonlocal ans
            p, q = l, mid + 1
            k = 0
            arr = []
            while p <= mid and q <= r:
                if nums[p] > nums[q]:
                    ans += mid - p + 1
                    arr.append(nums[q])
                    q += 1
                else:
                    arr.append(nums[p])
                    p += 1
                k += 1
            while p <= mid:
                arr.append(nums[p])
                p += 1
                k += 1
            while q <= r:
                arr.append(nums[q])
                q += 1
                k += 1
            for i in range(k):
                nums[i + l] = arr[i]

        n = len(nums)
        mergeSort(nums, 0, n - 1)
        return ans