#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    void dfs(vector<UndirectedGraphNode*> &nodes, vector<int> &path,
            unordered_set<UndirectedGraphNode*> &visit, UndirectedGraphNode* n) {
        visit.insert(n);
        path.push_back(n->label);
        for (auto &nn : n->neighbors) if (visit.find(nn) == visit.end()) {
            dfs(nodes, path, visit, nn);
        }
    }
    vector<vector<int> > connectedSet(vector<UndirectedGraphNode*>& nodes) {
        unordered_set<UndirectedGraphNode*> visit;
        vector<vector<int> > res;
        vector<int> path;
        for (auto &n : nodes) {
            if (visit.find(n) == visit.end()) {
                path.clear();
                dfs(nodes, path, visit, n);
                sort(path.begin(), path.end());
                res.push_back(path);
            } 
        }
        return res;
    }
};
int main() {
	Solution s;
	return 0;
}
