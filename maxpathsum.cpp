#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) :val(x),left(NULL),right(NULL){}
};


class Solution {
public:
	int maxPathSum(TreeNode *root) {
		int num = INT_MIN;
		maxPathSum(root, num);
		return num;
	}

	int maxPathSum(TreeNode* root,int &num) {
		if (root == NULL) {
			return 0;
		}
		int left = maxPathSum(root->left, num);
		int right = maxPathSum(root->right,num);
		int res = max(max(left + root->val,right + root->val),root->val);
		num = max(num, max(left+root->val+right,res));
		return res;
	}
};

int main() {
Solution s;
return 0;
}
