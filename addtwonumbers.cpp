#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x) :val(x), next(NULL){}
};
class Solution {
  public:
	ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
	       ListNode* dummy = new ListNode(0);
	       ListNode* pre = dummy;
	       int carry = 0;
               while(l1 != NULL || l2 != NULL) {
		   int value1 = l1 == NULL ? 0 : l1->val;
		   int value2 = l2 == NULL ? 0 : l2->val;
                   int value = value1 + value2 + carry;
                   pre->next = new ListNode(value % 10);
                   pre = pre->next;
                   carry = value / 10;
                   l1 = l1 == NULL? NULL : l1->next;
                   l2 = l2 == NULL? NULL : l2->next;
  		}
		if (carry > 0) {
			pre->next = new ListNode(carry);
		}
                return dummy->next;
	}
};


int main()
{
  Solution solution;
  ListNode *l1 = new ListNode(2);
  ListNode *p = l1;
  p->next = new ListNode(4);
  p = p-> next;
  p->next = new ListNode(3);
  ListNode *l2 = new ListNode(5);
  p = l2;
  p->next = new ListNode(6);
  p= p->next;
  p->next = new ListNode(4);
  ListNode *result = solution.addTwoNumbers(l1,l2);
  p = result;
  while(p != NULL) {
	cout<<p->val<<endl;
	p= p->next;
  } 	
  cout<<"Hello world!"<<endl;
  return 0;
}
