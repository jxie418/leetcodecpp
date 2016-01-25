#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int v):val(v), left(NULL),right(NULL){}
};

class Solution{

public:
int kthSmallest(TreeNode* root,int k) {
stack<TreeNode*> S;
bool isDone = false;
int i = 0 ;
	while(!isDone) {
		if (root != NULL) {
			S.push(root);
			root= root->left;
		} else if (S.empty()) {
			isDone = true;
		} else {
			root = S.top();
			S.pop();
			++i;
			if (i == k) {
				return root->val;
			}
			root = root->right;
			}
		}
	return 0;
}
};

int main() {
return 0;
}
