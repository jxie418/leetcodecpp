#include<cstdlib>
using namespace std;
struct TreeNode {
	TreeNode *left, *right;
	int val;
};
class Solution {
public:
	void reverseBST(TreeNode *root) {
		TreeNode *pre=0 ,  *first = 0, *second =0;
		find(root,pre, first, second);
		swap(first->val, second->val);
	}
	void find(TreeNode *root, TreeNode *pre, TreeNode *first, TreeNode *second) {
		if (!root) return;
		if(root->left) {
			find(root->left,pre,first, second);
		}
		if (pre && pre->val > root->val) {
			if (!first) {
				first = root;
			}
			second = root;
		}
		pre = root;
		if (root->right) {
			find(root->right, pre, first, second);
		}
	}
	void swap(int &v1, int &v2) {
		int tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
};

int main() {
	Solution s;
	return 0;
}
