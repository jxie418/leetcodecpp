class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<int, TreeNode*>> q;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(make_pair(0,root));
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; ++i){
                TreeNode* cur = q.front().second;
                int idx = q.front().first;
                q.pop();
                mp[idx].push_back(cur->val);
                if(cur->left) q.push(make_pair(idx-1, cur->left));
                if(cur->right) q.push(make_pair(idx+1,cur->right));
            }
        }
        for(auto m : mp){
            res.push_back(m.second);
        }
        return res;
    }
};
