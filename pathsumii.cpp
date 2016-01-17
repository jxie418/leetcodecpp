#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > res;
		vector<int> v;
		helper(res, root, sum, v);
		return res;
	}
	void helper(vector<vector<int> >& res, TreeNode *root, int sum, vector<int> &v) {
		if (root == NULL) {
			return ;
		}
		if (root->val == sum && root->left == NULL && root->right == NULL) {
		v.push_back(root->val);
		res.push_back(v);
		} else {
			vector<int> tmpLeft(v.begin(), v.end());
			tmpLeft.push_back(root->val);
			helper(res,root->left, sum-root->val, tmpLeft);
			vector<int> tmpRight(v.begin(), v.end());
			tmpLeft.push_back(root->val);
			helper(res, root->right, sum- root->val, tmpRight);
		}
	}
};
int main() {
Solution s;
return 0;
}
