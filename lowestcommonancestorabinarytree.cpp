#include<iostream>
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x):val(x),left(NULL),right(NULL) {}
};
class Solution {
public:
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode*p, TreeNode *q) {
	if (!root)
		return NULL;
	if (root == p || root == q) return root;
	TreeNode *L = lowestCommonAncestor(root->left,p,q);
	TreeNode *R = lowestCommonAncestor(root->right,p,q);
	if (L && R) 
		return root;
	return L ? L : R; 
		
}
};
int main() {
Solution s;
return 0;
}
