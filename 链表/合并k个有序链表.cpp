


/*
归并法
		l1 l2 l3 l4 l5
		| /   | /   |
		l6    l7
		|   /
		l8    / 
		l9

*/


//归并法 
ListNode *mergeKList(vector<ListNode*> lists) {
	return merge(list,0, lists.size()-1);
} 

ListNode *merge(ListNode *lists, int l, int r) {
	if (l == r) {
		return lists[l];
	}
	if (l >= r) {
		return NULL;
	}
	int mid = (l+r)>>1;
	ListNode *l = merge(lists, l, mid);
	ListNode *r = merge(lists, mid+1, r);
	return mergeTwoList(l,r);
}
ListNode *mergeTwoList(ListNode *a, ListNode *b) {
	ListNode head, *tail = head;
	ListNode *ha = a, *hb = b;
	while (ha && hb) {
		if (ha->val < hb->val) {
			tail->next = ha;
			ha = ha->next;
		}
		else {
			tail->next = hb;
			hb = hb->next;
		}
		tail = tail->next;
	}
	tail->next = ha ? ha : hb;
	return head.next; 
}

//顺序合并
ListNode *mergeKList(vector<ListNode*> lists) {
	ListNode *ans = NULL;
	for (int i = 0; i < n; i++) {
		ans = mergeTwoList(ans,lists[i]); 
	}
	return ans;
} 
