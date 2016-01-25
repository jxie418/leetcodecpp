#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
	map<int,int> M;
		for (int i = 0; i < nums.size() ; i ++) {
			if (M.find(nums[i]) != M.end()) {
				int j = M[nums[i]];
				if (abs(i -j) <= k) {
					return true;
				} 
			}
			M[nums[i]] = i;
		}
		return false;
	}
};

int main() {
	Solution s;
	return 0;
}
