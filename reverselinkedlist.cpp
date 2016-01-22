#include<iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};
using namespace std;

class Solution {
public: 
	ListNode *reverseList(ListNode *head) {
		ListNode *pre = NULL;
		while(head != NULL) {
			ListNode *next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};

int main() {
	Solution s;
	return 0;
}
