#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
     vector<vector<int> > combinationSum2(vector<int> & candidates, int target) {
     	vector<vector<int> > res;
	sort(candidates.begin(), candidates.end());
	vector<int> v;
	helper(res,candidates, target, v, 0);
	return res;
     }
     void helper(vector<vector<int> > & res, vector<int> & candidates, int target, vector<int> & v, int step) {
     	 if (target == 0) {
		res.push_back(v);
	 } else if (target > 0) {
		for (int i = step ; i < candidates.size() ; i++) {
			if (i > step && candidates[i-1]  == candidates[i]) {
				continue;
			}
			vector<int> newTemp;
			for (int j = 0; j < v.size(); j++) {
				newTemp.push_back(v[j]);
			}
			newTemp.push_back(candidates[i]);
			helper(res,candidates, target - candidates[i], newTemp, i+1);
		}
	 }
     }
};

int main() {
     	Solution s;
        vector<int> v;
        v.push_back(2);
        v.push_back(3);
        v.push_back(6);
        v.push_back(7);
        vector<vector<int> > res = s.combinationSum2(v,7);
        for (int i = 0 ; i < res.size() ; i++) {
             for (int j = 0; res[i].size(); j++) {
                   cout<<res[i][j]<<" ";
             }
             cout<<endl;
        }
        return 0;	
}
