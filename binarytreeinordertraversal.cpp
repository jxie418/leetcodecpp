#include<stack>
#include<vector>
#include<iostream>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
        TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL){}
};


class Solution {
public:
 	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> mystack;
		bool done = false;
		while(!done) {
			if (root != NULL) {
				mystack.push(root);
				root = root->left;
			} else if (mystack.empty()) {
				done = true;
			} else {
				root = mystack.top();
				mystack.pop();
				res.push_back(root->val);
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
