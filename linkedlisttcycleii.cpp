#include<iostream>
using namespace std;

struct {
	int val;
	ListNode *next;
	ListNode(int x):val(x) ,next(NULL){}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		ListNode *f = head;
		ListNode *s = head;
		while (f != NULL && f->next != NULL) {
			s = s->next;
			f = f->next->next;
			if ( s == f ) {
				break;
			}
		}
		if (s == f) {
			s = head;
			while(s != f) {
				s = s->next;
				f = f->next;
			}
			return s;
		}
		return NULL;
	}
};
int main() {
Solution s;
return 0;
}
