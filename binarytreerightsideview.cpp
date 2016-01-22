#include<vector>
#include<iostream>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL),right(NULL){}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode *root) {
		vector<int> res;
		if(root == NULL) {
			return res;
		}
		vector<TreeNode*> lay;
		lay.push_back(root);
		while(!lay.empty()) {
		bool isFirst = true;
		vector<TreeNode*> nextLay;
		for (int i = 0; i < lay.size(); i++) {
			if (isFirst) {
				res.push_back(lay[i]->val);
				isFirst = false;
			}
		
		if (lay[i]->right != NULL)
			nextLay.push_back(lay[i]->right);
		if (lay[i]->left != NULL)
			nextLay.push_back(lay[i]->left);
		}
		lay = nextLay;  
	}
	return res;
	}
};
int main() {
Solution s;
return 0;
}
