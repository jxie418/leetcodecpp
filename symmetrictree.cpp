#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};
class Solution {
public:
	bool isSymmetric(TreeNode *root) {

		if ( root == NULL ) {
			return true;
		}
		return isSymmetric(root->left,root->right);
	}
	bool isSymmetric(TreeNode* root1, TreeNode* root2) {
		if (root1 == NULL) {
			return root2 == NULL; 
		}
		if (root2 == NULL) {
			return false;
		}
		if (root1->val != root2->val) {
			return false;
		}
		
		return isSymmetric(root1->left,root2->right)&&isSymmetric(root1->right,root2->left);
	}
};

int main() {
	Solution s;
	return 0;
}
