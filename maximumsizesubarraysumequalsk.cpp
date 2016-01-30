#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
        int maxSubArrayLen(vector<int>& nums, int k) {
      		unordered_map<int, int> sums;
		int cur_sum = 0, max_len = 0;
		for (int i = 0 ; i < nums.size() ; ++i) {
			cur_sum += nums[i];
			if (cur_sum == k) {
				max_len = i + 1;
			} else if ( sums.find(cur_sum -k ) != sums.end() )  {
				max_len = max(max_len, i - sums[cur_sum - k]);
			}
			if ( sums.find(cur_sum) == sums.end() ) {
				sums[cur_sum] = i;
			}
		}
		return max_len;
	}
};
int main() {
	Solution s;
	return 0;
}
