#include<iostream>
using namespace std;


struct TreeLinkNode {
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x):val(x), left(NULL),right(NULL),next(NULL){}
};

class Solution {
public:
     	void connect(TreeLinkNode *root) {
     		if (root == NULL) {
			return;
		}
		TreeLinkNode *p = root->next;
		while ( p != NULL) {
			if (p ->left != NULL) {
				p = p ->left;
				break;
			}
			if (p ->right != NULL) {
				p = p ->right;
				break;
			}
			p = p->next;
		}
		if  (root->right != NULL) {
			root->right->next = p;
		}
		if (root->left != NULL) {
		       root->left->next = root->right == NULL? p :root->right;
		}
		connect(root->right);
		connect(root->left);
	}
};

int main() {
Solution s;
return 0;
}
