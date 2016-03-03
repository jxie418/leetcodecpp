class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = m ? rooms[0].size() : 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!rooms[i][j]) q.push({i, j});
        for (int d = 1; !q.empty(); d++) {
            for (int k = q.size(); k; k--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                add(rooms, q, i - 1, j, m, n, d);
                add(rooms, q, i + 1, j, m, n, d);
                add(rooms, q, i, j - 1, m, n, d);
                add(rooms, q, i, j + 1, m, n, d); 
            }
        }
    }
private:
    void add(vector<vector<int>>& rooms, queue<pair<int, int>>& q, int i, int j, int m, int n, int d) {
        if (i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] > d) {
            q.push({i, j});
            rooms[i][j] = d;
        }
    }
};
