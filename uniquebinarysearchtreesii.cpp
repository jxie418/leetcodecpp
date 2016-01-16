#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL),right(NULL){}
};

class Solution {
public:
vector<TreeNode*> generate(int start, int end) {
	vector<TreeNode*> result;
	if (start > end) {
		result.push_back(NULL);
		return result;
	}
	for (int i = start ; i <= end; i++) {
		vector<TreeNode* > leftsub = generate(start, i - 1);
		vector<TreeNode* > rightsub = generate(i+1, end);
		for (int m = 0 ; m < leftsub.size() ; m++) {
			for(int n = 0; n < rightsub.size(); n++) {
				TreeNode* root = new TreeNode(i);
				root->left = leftsub[m];
				root->right = rightsub[n];
				result.push_back(root);
			}
		}
	}
	return result;
}

vector<TreeNode* > generateTrees(int n) {
	if (n == 0) {
		vector<TreeNode *> result;
		return result;
	}
	return generate(1, n);
}
};
int main() {
	Solution s;
	
	return 0;
}
