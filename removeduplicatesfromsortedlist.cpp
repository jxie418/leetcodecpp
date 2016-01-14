#include<iostream>
using namespace std;

struct  ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode *head) {
	       if ( head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *pre = head, *next = head->next;
		while(next != NULL) {
			if ( pre->val == next->val ) {
				pre->next = next->next;
			} else {
				pre = next;
			}
	        	next = next->next;
		}
		return head;
	}
};

int main() {
	Solution s;
	return 0;
}
