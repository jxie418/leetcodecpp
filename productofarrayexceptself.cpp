#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(0,nums.size());

		res[0] = 1;
		int value = 1;
		for (int i = 1; i < nums.size() ; i++) {
			value *=nums[i - 1];
			res[i] = value;
		}
		value = 1;
		for (int i = nums.size() -2; i>=0; i--) {
			value *= nums[i+1];
			res[i] = res[i] * value;
		}
		return res;
	}
};

int main() {
	Solution s;
	return 0;
}
