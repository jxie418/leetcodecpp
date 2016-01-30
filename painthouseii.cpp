#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int> >& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int n = costs.size(), k = costs[0].size();
        vector<int> min1(k), min2(k);
        for (int i = 1; i < costs.size(); ++i) {
            min1[0] = INT_MAX;
            for (int j = 1; j < k; ++j) {
                min1[j] = min(min1[j-1], costs[i-1][j-1]);
            }
            min2[k-1] = INT_MAX;
            for (int j = k - 2; j >= 0; --j) {
                min2[j] = min(min2[j+1], costs[i-1][j+1]);
            }
            for (int j = 0; j < k; ++j) {
                costs[i][j] += min(min1[j], min2[j]);
            }
        }
        int res = INT_MAX;
        for (auto c : costs.back()) {
            res = min(res, c);
        }
        return res;
    }
};
