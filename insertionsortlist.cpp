#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode * insertionSortList(ListNode* head) {
		ListNode *dummy = new ListNode(0);
		ListNode *pre = dummy;
		while(head != NULL) {
			pre = dummy;
			while( pre->next != NULL && pre->next->val < head->val) {
				pre = pre->next;
			}
			ListNode *next = head->next;
			head->next = pre->next;
			pre->next = head;
			head = next;
		}
		return dummy ->next;
	}
};

int main() {
Solution s;
return 0;
}
