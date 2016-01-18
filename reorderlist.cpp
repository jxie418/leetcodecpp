#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};
class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return ;
		}
		ListNode* f = head;
		ListNode* s = head;
		ListNode*pre = s;
		while(f != NULL && f->next != NULL) {
			pre = s;
			s = s->next;
			f = f->next->next;
		}
		if ( f != NULL ) {
			pre = s;
			s = s->next;
		}
		pre->next = NULL;
		f = head;
		s = reverse(s);
		while(s != NULL) {
			ListNode*fn = f->next;
			ListNode*sn = s->next;
			f->next = s;
			s->next = fn;
			f = fn;
			s = sn;
		}
	}
	ListNode * reverse(ListNode *head) {
		ListNode *pre = NULL;
		while( head != NULL) {
			ListNode *next = head->next;
			head->next = pre;
			pre  = head;
			head = next;
		}
		return pre;
	}
};
int main() {
	Solution s;
	return 0;
}
