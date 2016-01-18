#include<iostream>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:

	bool hasCycle(ListNode *head) {
		if (head == NULL) {
			return false;
		} 
		ListNode *p = head;
		ListNode *q = head;
        	while(p != NULL && p->next != NULL) {
			p = p->next->next;
			q = q->next;
			if (p == q) {
				return true;
			}
		}
		return false;
	}
};
int main() {
	Solution s;
	return 0;
}
