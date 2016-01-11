#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSoFar = 0;
		int maxValue = INT_MIN;
		for(int i = 0; i < nums.size(); i++) {
			maxSoFar = max(nums[i], maxSoFar + nums[i]);
			maxValue = max(maxValue, maxSoFar);
		}
		return maxValue;
	}
};
int main() {
Solution s;
//int v[] = {−2,1,−3,4,−1,2,1,−5,4};
vector<int> nums;
nums.push_back(-2);
nums.push_back(1);
nums.push_back(-3);
nums.push_back(4);
nums.push_back(-1);
nums.push_back(2);
nums.push_back(1);
nums.push_back(-5);
nums.push_back(4);
cout<<s.maxSubArray(nums)<<endl;
return 0;
}
