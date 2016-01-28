#include<string>
#include<vector>
#include<iostream>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public: 
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (root == NULL) {
			return result;
		}
		findPaths(root, result,to_string(root->val));
		return result;
	}

void findPaths(TreeNode * root, vector<string> &result, string cur) {
	if (root->left == NULL && root->right == NULL) {
		result.push_back(cur);
		return;
	}
	if (root->left != NULL) {
		findPaths(root->left, result, cur+"->" + to_string(root->left->val));
	}
	if (root->right != NULL) {
		findPaths(root->right, result, cur+ "->"+ to_string(root->right->val));
	}
	}
};
int main() {
Solution s;
return 0;
}
