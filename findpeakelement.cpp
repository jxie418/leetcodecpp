#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		return findPeakElement(nums, 0, nums.size() -1);
	}
	int findPeakElement(vector<int> & nums, int low, int high){
		int mid = (low + high) >>1;
		if ((mid == 0 || nums[mid] > nums[mid-1])&&(mid == nums.size() || nums[mid] > nums[mid+1])) {
		return mid;
		} else if (mid >0 && nums[mid] < nums[mid -1]) {
			return findPeakElement(nums, low, mid -1);
		} else {
			return findPeakElement(nums, mid + 1, high);
		}
	}
};

int main() {
Solution s;
return 0;
}
