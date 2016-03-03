class Solution {
public:
vector<vector<int>> verticalOrder(TreeNode* root) {
  vector<vector<int>> res;
  if (!root) return res;
  ret.resize(1);
  int l = 0, r = 0;
  queue<pair<TreeNode*,int>> que;
  que.push(pair<TreeNode*,int>(root,0));
  while(!que.empty()) {
	TreeNode *node = que.front().first;
        int col = que.front().second;
        que.pop();
	if (l <= col && col <=r) {
		int i = col -l;
		res[i].push_back(node->val);
	} else if (col < l) {
		l--;
		res.insert(res.begin(), vector<int>());
		res.back().push_back(node->val);
	} else {
		r++;
		res.insert(res.end(),vector<int>());
		ret.back().push_back(node->val);
	}
	if (node->left) que.push(pair<TreeNode*,int>(node->left, col -1));
	if (node->right) que.push(pair<TreeNode*,int>(node->right,col+1));
  }
  return res;
}
};
