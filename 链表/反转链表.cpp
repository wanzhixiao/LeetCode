#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	
	ListNode(int val) : val(val), next(NULL) {
	}
};

/*

1,2,3

*/

int main(){
	
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	
	ListNode *pre = NULL, *cur = head;
	
	while (cur != NULL) {
		ListNode *tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	while (pre != NULL) {
		cout << pre->val << " ";
		pre = pre->next;
	}
	cout << endl;
	
	return 0;
}
