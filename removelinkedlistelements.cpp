#include<iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public: 
	ListNode * removeElements(ListNode *head, int val) {
		ListNode * dummy = new ListNode(0);
		dummy->next = head;
		ListNode * pre = dummy;
		while ( head != NULL) {
			if ( head->val == val ) {
				pre->next = head->next;
			} else {
				pre = head;
			}
			head = head->next;
		} 
		return dummy->next;
	}
};

int main() {
	Solution s;
	return 0;
}
