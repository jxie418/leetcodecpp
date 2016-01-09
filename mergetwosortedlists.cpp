#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0);
		ListNode* pre = dummy;
		while(l1 != NULL && l2 != NULL) {
		   if (l1->val < l2-> val) {
			pre->next = l1;
			l1 = l1->next;
		   } else {
			pre->next = l2;
			l2 = l2 ->next;
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
	ListNode *l1 = new ListNode(0);
	ListNode *p = l1;
        p->next = new ListNode(1);
	p = new ListNode(2);
	ListNode *l2 = new ListNode(4);
	p = l2;
	p->next = new ListNode(5);
	ListNode *head = s.mergeTwoLists(l1,l2);
	p = head;
        while(p != NULL) {
		cout << p->val<< " ";
		p = p->next;
	}
	cout<<endl;
	return 0;
}
