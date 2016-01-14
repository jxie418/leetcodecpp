#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
     vector<vector<int> > subsets(vector<int> & nums) {
	vector<vector<int> > res;
	if ( nums.size() == 0) {
		return res;
	}
	vector<int> v;
	res.push_back(v);
	sort(nums.begin(), nums.end());
	for(int i = 0 ; i < nums.size() ; i++) {
		int size = res.size();
		for (int j = 0; j < size ; j++) {
		    vector<int> tmp(res[j].begin(), res[j].end());
		    tmp.push_back(nums[i]);
		    res.push_back(tmp);
		}
	}
	return res;
     }
};

int main() {
Solution s;
vector<int> nums;
nums.push_back(1);
nums.push_back(2);
nums.push_back(3);
vector<vector<int> > res = s.subsets(nums);
for (int i = 0; i < res.size(); i++) {
	for (int j = 0; j < res[0].size(); j++) {
		cout<< res[i][j]<<" ";
	}
	cout<<endl;
}
return 0;
}
