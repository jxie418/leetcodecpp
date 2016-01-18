#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
int findMin(vector<int> & nums) {
	int L = 0;
	int R = nums.size() - 1;
	while(L < R && nums[L] >= nums[R]) {
		int mid = (L+R) >> 1;
		if (nums[mid] > nums[R]) {
			L = mid + 1;
		} else if (nums[mid] < nums[R]) {
			R = mid;
		} else {
			L ++;
		}
	}
	return nums[L];
}
};

int main() {
Solution s;
return 0;
}

