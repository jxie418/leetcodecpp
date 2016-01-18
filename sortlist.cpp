#include<iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode * sortList(ListNode * head) {
		return divide(head);
	}

	ListNode * divide(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *s = head;
		ListNode *f = head;
		ListNode *pre = s;
		while(f != NULL && f->next != NULL) {
			pre = s;
			s = s->next;
			f = f->next->next;
		}
		pre->next = NULL;
		return merge(divide(head),divide(s));
	}
	ListNode *merge(ListNode *l1, ListNode *l2) {
		ListNode *dummy = new ListNode(0);
		ListNode *pre = dummy;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val > l2->val) {
				pre->next = l2;
				l2 = l2->next;
			} else {
				pre->next = l1;
				l1 = l1->next;
			}
  			pre = pre->next;
		}
		if (l1 != NULL) {
			pre->next = l1;
		}
		if (l2 != NULL) {
			pre->next = l2;
		}
		return dummy->next;
	}
};

int main() {
Solution s;
return 0;
}
