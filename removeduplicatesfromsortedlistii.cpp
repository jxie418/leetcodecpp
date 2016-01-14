#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
	public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy;
		while( head != NULL) {
			ListNode *nextNodeDiff = head->next;
			while( nextNodeDiff != NULL && head->val == nextNodeDiff->val ) {
				nextNodeDiff = nextNodeDiff->next;
			}
 			if ( head->next == nextNodeDiff ) {
				pre = head;
				head = head->next;
			} else {
				while( head != nextNodeDiff ) {
					ListNode *next = head->next;
					head->next = NULL;
					head = next;
				}
				pre->next = head;
			}
		}
		return dummy->next;
	}
};

int main() {
	Solution s;
	
	return 0;
}


