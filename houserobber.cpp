#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int even = 0, odd = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i%2 == 0) {
				even = max(nums[i] + even, odd);
			} else {
				odd = max(nums[i]+odd, even);
			}
		}
		return max(even, odd);
	}
};

int main() {
	Solution s;
	return 0;
}
