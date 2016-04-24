class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX, val = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum = grid;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    vector<vector<int>> dist = grid;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        int i = q.front().first, j = q.front().second; q.pop();
                        for (int k = 0; k < dirs.size(); ++k) {
                            int x = i + dirs[k][0], y = j + dirs[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) {
                                --grid[x][y];
                                dist[x][y] = dist[i][j] + 1;
                                sum[x][y] += dist[x][y] - 1;
                                q.push({x, y});
                                res = min(res, sum[x][y]);
                            }
                        }
                    }
                    --val;                    
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
