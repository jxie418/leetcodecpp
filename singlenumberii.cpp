#include<vector>
#include<string>

using namespace std;


class Solution {
public :
int singleNumber(vector<int>& nums) {
	int res = 0;
	int dp[32];
	memset(dp,0,32*sizeof(int));
	for(int i = 0; i < 32; i ++) {
 		for (int j = 0; j < nums.size(); j++) {
			dp[i] +=(nums[j] >> i)&1;
		}
		res |=(dp[i] % 3) << i;
	}
	return res;
	}
};

int main() {
	Solution s;
	return 0;
}
