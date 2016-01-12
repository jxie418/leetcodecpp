#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int n) {
		int len = getLen(head);
		if(len == 0) {
			return head;
		}
		if(len <= n) {
			n =n % len; 
		}
		if (n == 0) {
			return head;
		}
		n = len - n;
		ListNode *dummy = new ListNode(0);
                dummy->next = head;
		ListNode *pre = dummy;
		ListNode *p = head;
		while(p != NULL && n--> 0 ) {
			pre = p;
			p = p->next;
		}
		pre->next = NULL;
		ListNode *rear = p;
		while(rear->next != NULL) {
		    rear = rear->next;
		}
		rear->next = dummy->next;
		return p;
	}
	int getLen(ListNode *head) {
		int len = 0;
		while(head != NULL) {
			++len;
			head = head -> next;
		}
		return len;
	}
};
int main() {
	Solution s;
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	return 0;
}
