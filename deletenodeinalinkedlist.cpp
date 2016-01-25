#include<iostream>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	void deleteNode(ListNode *node) {
		ListNode *pre = node;
		while(node->next != NULL) {
			node->val = node->next->val;
			pre= node;
			node = node->next;
		}
		pre->next = NULL;
	}
};

int main() {
Solution s;
return 0;
}
