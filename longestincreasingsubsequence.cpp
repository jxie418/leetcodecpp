#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
int lengthOfLIS(vector<int>&nums) {
	if(nums.empty()) return 0;
	int len = nums.size();
	vector<int> lis(len,1);
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i] && lis[i] < lis[j] + 1) {
				lis[i] = 1 + lis[j];
			}
		}
	}
	return *max_element(lis.begin(),lis.end());
}
};

int main() {
Solution s;
return 0;
}
