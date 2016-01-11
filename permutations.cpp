#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<vector<int> > permute(vector<int>& nums) {
	    vector<vector<int> > res;
	    if(nums.size() == 0) {
		return res;
	    }  
	    sort(nums.begin(),nums.end());
	    bool dp[nums.size()];
	    memset(dp,0, nums.size()* sizeof(bool));
	    vector<int> v;
	    helper(res, nums,dp,v);
	    return res;
	}
	void helper (vector<vector<int> > &res, vector<int> &nums, bool dp[],vector<int>&v) {
	   if (nums.size() == v.size()) {
		res.push_back(v);
	   } else if (v.size() < nums.size()) {
		for (int i = 0; i < nums.size() ; i++) {
			if (!dp[i]) {
				vector<int> tmp(v.begin(),v.end());
				tmp.push_back(nums[i]);
				dp[i] = true;
				helper(res, nums, dp,tmp);
				dp[i] = false;
			}
		}
	   }
	}
};
int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    vector<vector<int> > res = s.permute(nums);
    for (int i = 0; i < res.size() ; i++) {
	for(int j = 0 ; j < res[i].size() ; j++) {
		cout<<res[i][j]<<" ";
	}
        cout<<endl;
    }
    return 0;
}
