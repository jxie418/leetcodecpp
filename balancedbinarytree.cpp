#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL),right(NULL){}
};
class Solution {

public :
	bool isBalanced(TreeNode *root) {
		if (root == NULL) {
			return true;
		}
		int left = getDepth(root->left);
		int right = getDepth(root->right);
		return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
	int getDepth(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}
		int left = getDepth(root->left);
		int right = getDepth(root->right);
		return max(left,right) + 1;
	}
};

int main() {
Solution s;
return 0;
}
