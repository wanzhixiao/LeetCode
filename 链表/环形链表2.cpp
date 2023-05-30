#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int val) : val(val), next(NULL) {
	}
	~ListNode() {
		ListNode *p = this;
		while(p) {
			ListNode *tmp = p;
			cout << "delete "<< p->val << endl;
			p = p->next;
			delete tmp;
			tmp = NULL;
		}
		p = NULL;
	}
}; 

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast && fast->next) {
    	slow = slow->next;
    	fast = fast->next->next;
    	if (slow == fast) {
    		fast = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow; 
		}
	}
	return NULL; 
}

/*

1->2->3->4->5->6
		 |	   |
		  9-8-7 

s = x + y
f = x + n(y+z) + y

n = 1;
f = 2s

2(x+y) = x+(y+z)+y
x+y = y+z
x=z
*/

int main() {
	vector<int> list = {1,2,3,4,5,6,7,8,9};
	ListNode *head = new ListNode(list[0]);
	ListNode *tail = head, *p = NULL;
	ListNode *pcycle_enter = NULL;
	
	for (int i = 1; i < list.size(); i++) {
		p = new ListNode(list[i]);
		tail->next = p;
		tail = p;
		
		if (i == 3) {
			pcycle_enter = p;
		}
	}
	
	tail->next = pcycle_enter;
	ListNode *pa = detectCycle(head);
	cout << "ans = " << pa->val << endl;
	
	p = head;
	int cnt = 0;
	while (p) {
		cout << p->val << " ";
		p = p->next;
		
		if (p->val == 4) {
			++cnt;
		}
		if (cnt == 2) {
			break;
		}
	}
	cout << endl;
	return 0;
}
