#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if ( nums.size() == 0 ) {
			return 0;
		}
		int len = nums.size();
		int start = 0 , end = 0, sum = 0;
		int minValue = len + 1;
		while(end < len && sum <= s ) {
			while(end <len && sum < s) {
				sum+= nums[end];
				++end;
			}
			while(start < end && sum >= s) {
				minValue = min(minValue, end - start);
				sum -=nums[start++];
			}
		}
		return minValue < len + 1 ? minValue : 0;
	}
};

int main() {
Solution s;
return 0;
}
