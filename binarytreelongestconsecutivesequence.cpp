#include<iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return longest(root, NULL, 0);
    }
private:
    int longest(TreeNode* now, TreeNode* parent, int len) {
        if (!now) return len;
        len = (parent && now->val == parent->val + 1) ? len + 1 : 1;
        return max(len, max(longest(now->left, now, len), longest(now->right, now, len)));
    }
};

int main() {
	Solution s;
	return 0;
}
