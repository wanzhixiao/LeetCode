
'''
合并k个升序链表
方法：归并法（分治）
    分解问题为两个子问题
    合并子问题的解为原问题
    1. 分， 将原问题一分为2
    2. 合并， 合并两个升序链表，尾插法
'''
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        return self.mergeSort(lists, 0, len(lists)-1)

    def mergeSort(self,lists,l, r):
        if l>=r:
            return lists[l]
        mid = (l+r)//2
        left = self.mergeSort(lists, l, mid)
        right = self.mergeSort(lists, mid+1, r)
        return self.merge(left, right)

    def merge(self, list1,list2):
        if not list1:
            return list2
        if not list2:
            return list1

        head = list1 if list1.val < list2.val else list2
        p, q = list1, list2
        tail = None
        while p and q:
            if p.val < q.val:
                if not tail:
                    tail = p
                else:
                    tail.next = p
                    tail = p
                p = p.next
            else:
                if not tail:
                    tail = q
                else:
                    tail.next = q
                    tail = q
                q = q.next
        if p:
            tail.next = p
        if q:
            tail.next = q
        return head