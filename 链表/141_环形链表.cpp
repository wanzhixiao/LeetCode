#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int val): val(val), next(NULL) {
	} 
};

bool hasCycle(ListNode *head) {
    
    ListNode *fast = head, *slow = head;
    
    while (fast && fast->next) {
    	fast = fast->next;
    	fast = fast->next;
    	slow = slow->next;
    	
    	if (slow == fast) {
//    		cout << slow->val << " " << fast->val << endl;
    		return true;
		}
	}
    
    return false;
}

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    int cnt = 0;
    
    while (fast && fast->next) {
    	fast = fast->next;
    	fast = fast->next;
    	slow = slow->next;
    	
    	if (slow == fast) {
			ListNode *p = head;
            while(p!=slow){
                slow=slow->next;
                p=p->next;
            }
            return p;
		}
	}
    
    return NULL; 
}

int main() {
	int n = 6; 
	int arr[] = {0,1,2,3,4,5};
	
	ListNode *p = new ListNode(arr[0]);
	ListNode *head = p;
	ListNode *tail = p;
	
	for (int i = 1; i < n; i++) {
		p = new ListNode(arr[i]);
		tail->next = p;
		tail = p;
	}
	
	tail->next = head->next;
	
//	cout << hasCycle(head) << endl;
	
	ListNode *q = detectCycle(head);
	cout << q->val << endl;
	
//	p = head; 
//	while (p) {
//		cout << p->val << " ";
//		p = p->next;
//	}
//	cout << endl;
	return 0;
} 
