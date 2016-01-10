#include<iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};

class Solution {
	public:
	ListNode* reverseKGroup(ListNode * head, int k) {
		if (head == NULL || k == 1) {
		      return head;
		}
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy;
	        int i = 0;
		while(head != NULL) {
			i++;
			if (i % k == 0) {
				pre = reverse(pre, head->next);
				head = pre->next;
			} else {
				head = head->next;
			}
		}
                return dummy->next;
	}
	
	ListNode* reverse(ListNode *pre, ListNode *next) {
		if (pre == NULL) {
			return pre;
		}
		ListNode *res = pre ->next;
		ListNode *newPre = next;
		ListNode *p = pre->next;
		while(p != next) {
			ListNode *q = p -> next;
			p-> next = newPre;
			newPre = p;
			p = q;
		}
		pre->next = newPre;
		return res;
	}
};

int main() {
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
        p->next = new ListNode(4);
	p = head;
	while(p != NULL) {
	   cout<<p->val<<" ";
	   p = p->next;
	}
	cout<<endl;
	head = s.reverseKGroup(head, 2);
	p = head;
	while(p!= NULL) {
	   cout<<p->val<<" ";
	   p = p->next;
	}
	cout<<endl;
	cout<<"Done"<<endl;
}
