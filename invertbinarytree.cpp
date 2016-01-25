#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode  *left;
	TreeNode  *right;
	TreeNode(int x) : val(x), left(NULL),right(NULL){}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) {
			return NULL;
		}
		queue<TreeNode*> Q;
		Q.push(root);
		while( !Q.empty() ) {
			TreeNode * node = Q.front();
			Q.pop();
			TreeNode* tmp = node->left;
			node->left = node->right;
			node->right = tmp;
			if (node->left != NULL) {
				Q.push(node->left);
			}
			if (node->right != NULL) {
			      Q.push(node->right);
			}
		}
		return root;
	}
};
int main() {
	Solution s;
        return 0;
}
