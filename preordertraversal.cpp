#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL),right(NULL){}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode * root) {
		stack<TreeNode*> S;
		bool isDone = false;
		vector<int> res;
		while(!isDone) {
			if (root != NULL) {
				res.push_back(root->val);
				S.push(root);
				root = root->left;
			} else if (S.empty()) {
				isDone = true;
			} else {
				root = S.top();
				S.pop();
				root = root->right;
			}
		}
		return res;
	}
};
int main() {
	Solution s;
	return 0;
}
