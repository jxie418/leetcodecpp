#include<iostream>



using namespace std;


struct TreeNode{
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x):val(x), left(NULL),right(NULL){}
};


class Solution {

public:
	int sumNumbers(TreeNode *root) {
		return sumNumbers(root,0);
	}
	int sumNumbers(TreeNode *root, int val) {
		if (root == NULL) {
			return 0;
		}
		val = root->val + val * 10;
		if (root->left == NULL && root->right == NULL) {
			return val;
		}	
		return sumNumbers(root->left, val) + sumNumbers(root->right,val);
	}

};

int main() 
{
	return 0;
}
