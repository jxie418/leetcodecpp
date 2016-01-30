#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    int findFather(vector<int> &father, int x) {
        while (x != father[x]) x = father[x];
        return x;
    }
    bool dfs(vector<vector<int> > &graph, vector<bool> &visit, int u, int f) {
        visit[u] = true;
        for (auto v : graph[u]) if (v != f) {
            if (visit[v]) return false;
            else if (!dfs(graph, visit, v, u)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> father(n);
        for (int i = 0; i < n; ++i) father[i] = i;
        for (auto edge : edges) {
            int fa = findFather(father, edge.first), fb = findFather(father, edge.second);
            if (fa < fb) father[fb] = fa;
            else father[fa] = fb;
        };
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == father[i]) ++cnt;
            if (cnt > 1) return false;
        }
        vector<vector<int>> graph(n);
        vector<bool> visit(n, false);
        for (auto edge : edges) {
            int u = edge.first, v = edge.second;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return dfs(graph, visit, 0, -1);
    }
};
