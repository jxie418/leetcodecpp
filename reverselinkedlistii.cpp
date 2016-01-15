#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
	public:
	ListNode* reverseBetween(ListNode *head, int m, int n) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = dummy;
		while ( p != NULL && --m > 0 ) {
			p = p->next;
		}
		ListNode *q = head;
		while ( q != NULL && n-- > 0 ) {
			q = q->next;
		}
		reverse(p, q);
		return dummy->next;
	}
	void reverse( ListNode * pre, ListNode * n) {
		if (pre == NULL) {
			return;
		}
		ListNode *nextHead = pre->next;
		ListNode *newPre = n;
		ListNode *p = pre->next;
		while ( p != n ) {
			ListNode *next = p -> next;
			p->next = newPre;
			newPre = p;
			p = next;
		}
		pre->next = newPre;
	}
};
int main() {
	Solution s;
	return 0;
}
