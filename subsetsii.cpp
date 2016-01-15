#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int> > allSets(1);
		vector<int> sol;
		sort(S.begin(),S.end());
		findSubsetsWithDup(S,0,sol,allSets);
		return allSets;
	}
	void findSubsetsWithDup(vector<int> &S, int start, vector<int>&sol, vector<vector<int> > & allSets) {
	  for (int i = start; i < S.size(); i++) {
		if (i > start && S[i] == S[i -1]) {
			continue;
		}
		sol.push_back(S[i]);
		allSets.push_back(sol);
		findSubsetsWithDup(S, i+1,sol, allSets);
		sol.pop_back();
	  }
	}
};
int main() {
Solution s;
return 0;
}
