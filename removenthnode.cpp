#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};
class Solution {
	public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy;
		ListNode *p = head;
		while(p != NULL && n-- > 0) {
			p = p->next; 
		}
		if (p == NULL) {
		    return head->next;
		}
		ListNode *q = head;
	        while(p != NULL) {
		   pre = q;
		   q = q-> next;
		   p = p-> next;
		}
	        if (q != NULL) {
		    pre->next = q->next;
		    q->next = NULL;
		}
		return dummy->next;
	}
};
int main() {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p = head;
    while(p != NULL) {
	cout<<p->val<<" ";
	p = p->next;
    }
    cout<<endl;
    Solution s;
    head = s.removeNthFromEnd(head, 2);
    p = head;
    while(p != NULL) {
	cout<<p->val<<" ";
	p = p->next;
    }
    cout<<endl;			
}
