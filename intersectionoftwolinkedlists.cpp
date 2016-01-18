#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
ListNode *getIntersectionNode(ListNode* headA, ListNode *headB) {
	int len1 = getLen(headA);
	int len2 = getLen(headB);
	if (len2 > len1) {
		return getIntersectionNode(headB, headA);
	}
	int diff = len1 - len2;
	while(headA != NULL && diff--> 0) {
		headA = headA->next;
	}
	while(headA != NULL && headB != NULL) {
		if (headA == headB) {
			return headA;
		}
		headA = headA ->next;
		headB = headB ->next;
	}
	return NULL;
}
int getLen(ListNode *head) {
	int count = 0;
	while(head != NULL) {
		++count;
		head = head->next;
	}
	return count;
}
};

int main() {
	Solution s;
	return 0;
}
