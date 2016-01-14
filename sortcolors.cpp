#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int dp[3] = {0,0,0};
		for (int i = 0; i < nums.size() ; i++) {
			dp[nums[i]]++;
		}
		dp[1] += dp[0];
		dp[2] += dp[1];
		int i = 0;
		while ( i < dp[0]) {
			nums[i++] = 0;
		}
		while ( i < dp[1]) {
			nums[i++] = 1;
		}
		while ( i < dp[2]) {
			nums[i++] = 2;
		}
	}
};
int main() {
	Solution s;
	return 0;	
}
