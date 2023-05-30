/*

这道题的难点在于怎么重接链表， 使得可以进行下一次翻转 
1. 求链表长度
2. k个一组反转
3. 接上指针


	1 2 3 4
	 
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode *p = head;
        while(p) {
            p = p->next;
            n+=1;
        }
        ListNode *dummy = new ListNode(0,head);
        p = dummy;
        ListNode *cur = dummy->next, *pre = NULL;
        while (n >= k) {

            for (int i = 0; i < k; i++) {
                ListNode *tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }

            ListNode *nxt = p->next;
            p->next->next = cur;
            p->next = pre;
            p = nxt;

            n -= k;
        }
        return dummy->next;
    }
};
