
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
92.��ת���� II
	��תleft, right֮�������
  ˼·�� 
  	1.��¼left֮ǰ��һ���ڵ�Ϊp 
  	2.��ת left��right������
	3. p->next->next = cur;
	   p->next = pre 
	��left=0, ��ˣ���Ҫ����һ��ָ��head�ڵ���ƽڵ�dummy 
	p = dummy

25 k��һ�鷴ת���� 
˼·��https://www.bilibili.com/video/BV1sd4y1x7KN/?spm_id_from=333.788&vd_source=843e98298bc70b0e35331918314486ce
1. ���������¼����ĳ���
2. k��һ�鷴ת , ����k���������ת 
��¼����ת�����ǰһ���ڵ�p�� ��ת�����k���ڵ�

 ��ת����
 	next = cur->next;
	cur->next = pre;
	pre = cur;
	cur = next; 

ÿ�η�ת��Ĵ��� 
 ����nxt = p->next ,  ��Ϊ��һ�η�ת��ǰһ���ڵ�
 p->next->next = cur;
 p->next = pre
 p = nxt;
*/
