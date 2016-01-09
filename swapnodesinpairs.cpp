#include<iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

using namespace std;
class Solution {
	public:
	  ListNode* swapPairs(ListNode * head) {
	    if (head == NULL || head->next == NULL) {
		return head;
	    } 
	    ListNode *newHead = head -> next;
	    head->next = swapPairs(newHead->next);
	    newHead->next = head;
	    return newHead;
	 }
};

int main() {
	Solution s;
	ListNode* h1 = new ListNode(1);
	ListNode* p = h1;
        p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);	
	p = p->next;
	p->next = new ListNode(4);
	p = h1;
        while(p != NULL) {
	  cout<<p->val<<" ";
	  p = p-> next;
	}
	cout<<endl;
        h1 = s.swapPairs(h1);
	p = h1;
	while(p != NULL) {
	  cout<<p->val<<" ";
	  p= p->next;
	}
	cout<<endl;
}
