#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int val) : val(val), next(NULL) {
	} 
}; 

ListNode *swapNode(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	} 
	ListNode *next = head->next;
	head->next = swapNode(next->next);
	next->next = head;
	return next; 
}

/*
        a->b->c
        
        反转思路： 把c当做后序待交换的子问题，让a指向c, b指向a 
		b->a->c
*/

int main() {
	int n = 6;
	int nums[] = {1,2,3,4,5,6};
	ListNode *head = new ListNode(nums[0]);
	ListNode *tail = head;
	
	for (int i = 1; i < n; i++) {
		ListNode *p = new ListNode(nums[i]);
		tail->next = p;
		tail = p;
	}
	
	head = swapNode(head);
	
	ListNode *first = head, *second = head->next;
	
	while (first && second) {
		int tmp = first->val;
		first->val = second->val;
		second->val = tmp;
		
		first = second->next;
		
		if (first) {
			second = first->next;
		}
	}
	ListNode *p = head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

 	return 0;
} 

/*

1 2 3 4 5
2 1 4 3 5
*/

