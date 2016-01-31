#include<iostream>

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
	TreeNode *inorderSuccess(TreeNode *root, TreeNode*p) {
		if (p == NULL) return NULL;
		TreeNode *res = NULL;
		if (p->right) {
			res = p->right;
			while(res->left)
				res = res->left;
			return res; 
		}
		TreeNode * q = root;
		while(q && q->val != p->val) {
			if (q->val > p->val) {
				res = q;
				q = q->left;
			} else {
				q = q->right;
			}
		}
		return res;
	}
};

int main() {
Solution s;
return 0;
}
