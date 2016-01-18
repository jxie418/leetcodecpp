#include<vector>
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		if (root == NULL) {
			return res;
		}
		stack<TreeNode*> S;
		S.push(root);
		TreeNode *pre = NULL;
		while(!S.empty()) {
			TreeNode *p = S.top();
			if ((p->left == NULL && p->right == NULL)|| (pre != NULL &&(pre ==p->left || pre== p->right))) {
				res.push_back(p->val);
				S.pop();
				pre = p;
			} else {
				if (p->right) {
					S.push(p->right);
				} 
				if (p->left) {
					S.push(p->left);
				}
			}
		}
		return res;
	}
};

int main() {
Solution s;
return 0;
}
