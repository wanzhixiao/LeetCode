
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dumy = new ListNode(0, head);
        ListNode *p = dumy;
        ListNode *pre = NULL;
        for (int i = 0; i < left-1; i++) {
            p = p->next;
        }

        ListNode *cur = p->next;
        for (int i = 0; i < right-left+1; i++) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        p->next->next = cur;
        p->next = pre;
        return dumy->next;
    }
	
    ListNode* reverseKGroup(ListNode* head, int k) {

        int n = 0;
        ListNode *p = head;
        while (p != NULL) {
            n += 1;
            p = p->next;
        }

        ListNode *dumy = new ListNode(0, head);
        p = dumy;
        ListNode *pre = NULL;
 
        ListNode *cur = p->next;
        while (n >= k) {

            for (int i = 0; i < k; i++) {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            ListNode *nxt = p->next;
            p->next->next = cur;
            p->next = pre;
            p = nxt;

            n -= k;
        }
        return dumy->next;

    }
};

/*
92.反转链表 II
	反转left, right之间的链表
  思路： 
  	1.记录left之前的一个节点为p 
  	2.反转 left到right的链表
	3. p->next->next = cur;
	   p->next = pre 
	若left=0, 因此，需要建立一个指向head节点的哑节点dummy 
	p = dummy

25 k个一组反转链表 
思路：https://www.bilibili.com/video/BV1sd4y1x7KN/?spm_id_from=333.788&vd_source=843e98298bc70b0e35331918314486ce
1. 遍历链表记录链表的长度
2. k个一组反转 , 不足k个则结束反转 
记录待反转链表的前一个节点p， 反转后面的k个节点

 反转链表
 	next = cur->next;
	cur->next = pre;
	pre = cur;
	cur = next; 

每次反转后的处理 
 保存nxt = p->next ,  作为下一次反转的前一个节点
 p->next->next = cur;
 p->next = pre
 p = nxt;
*/
