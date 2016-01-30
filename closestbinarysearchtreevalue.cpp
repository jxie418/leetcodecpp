#include<iostream>
#include<vector>
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int v):val(v),left(NULL),right(NULL){}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (!root) return INT_MAX;
        if (!(root -> left) && !(root -> right)) return root -> val;
        int left = closestValue(root -> left, target);
        int right = closestValue(root -> right, target);
        double td = abs(root -> val - target), ld = abs(left - target), rd = abs(right - target);
        if (td < ld) return td < rd ? root -> val : right;
        else return ld < rd ? left : right;
    }
};

