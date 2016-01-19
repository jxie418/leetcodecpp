#include<stack>
#include<iostream>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL), right(NULL){}
};

class BSTIterator{
private:
	stack<TreeNode*> mystack;
	TreeNode* root;
public:
	BSTIterator(TreeNode * r) {
		root = r;
	}
	bool hasNext() {
		return (root != NULL || !mystack.empty());
	}
	int next() {
		while(root != NULL) {
			mystack.push(root);
			root = root ->left;
		}
		if (mystack.empty()) {
			return -1;
		}
		root = mystack.top();
		mystack.pop();
		int value = root->val;
		root = root->right;
		return value;
	}
};
int main() {
return 0;
}
