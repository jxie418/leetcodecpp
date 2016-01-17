#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		while(root != NULL) {
			if (root->left != NULL) {
				TreeNode *p = root->left;
				while(p->right != NULL) {
					p = p ->right;
				}
				p->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
	}
};
int main() {
	Solution s;
	return 0;
}
