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
	bool isSameTree(TreeNode* root1, TreeNode* root2) {
		if (root1 == NULL) {
			return root2 == NULL; 
		}
		if (root2 == NULL) {
			return false;
		}
		if (root1->val != root2->val) {
			return false;
		}
		
		return isSameTree(root1->left,root2->left)&&isSameTree(root1->right,root2->right);
	}
};

int main() {
	Solution s;
	return 0;
}
