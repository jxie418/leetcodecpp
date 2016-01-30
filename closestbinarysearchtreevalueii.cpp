#include<iostream>
#include<vector>
#include<priority_queue>
using namespace std;
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
TreeNode(x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> pq;
        closestK(root, pq, target, k);
        vector<int> closest;
        while (!pq.empty())
            closest.push_back(pq.top().second), pq.pop();
        return closest;
    }
private:
    void closestK(TreeNode* node, priority_queue<pair<double, int>>& pq, double target, int k) {
        if (!node) return;
        pq.push(make_pair(abs(target - node -> val), node -> val));
        if (pq.size() > k) pq.pop();
        closestK(node -> left, pq, target, k);
        closestK(node -> right, pq, target, k);
    }
};
