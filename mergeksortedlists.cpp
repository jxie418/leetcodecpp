#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

template<typename T> void print_queue(T & q) {
   while(!q.empty()) {
	cout<<q.top()<<" ";
	q.pop();
   }
   cout<<endl;
}
struct ListNode {
	int val;
	ListNode *next;
	bool operator> (const ListNode  *t) const { return val >  t->val;};
        bool operator>=(const ListNode  *t) const { return val >= t->val;};
	bool operator==(const ListNode  *t) const { return val == t->val;};
	bool operator< (const ListNode  *t) const { return val <  t->val;};
	bool operator<=(const ListNode  *t) const { return val <= t->val;};
	ListNode (int x): val(x), next(NULL){}
};

class Solution {
	public :
	  ListNode* mergeKLists(vector<ListNode*> &lists) {
		if (lists.size() == 0)
			return NULL;
                priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*> > q;
	        for (int i = 0 ; i < lists.size() ; i++) {
			q.push(lists[i]);
		}
		ListNode* dummy = new ListNode(0);
		ListNode* p = dummy;
		while(!q.empty()) {
			ListNode * temp = q.top();
			q.pop();
			p->next = temp;
			if (temp->next != NULL) 
				q.push(temp->next);
			p = p ->next;
		}
		return dummy->next;
	  }
};
int main() {
    priority_queue<int,vector<int>, greater<int> > q;
    int nums[] = {1,8,5,6,3,4,0,9,7,2};
    for(int i = 0; i < 10; i++) {
	q.push(nums[i]);
    }
    print_queue(q);
}
