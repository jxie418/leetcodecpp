#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int> & nums, int k) {
		if ( k < 1 || nums.size() == 0 ) {
			return 0;
		}
		return getKth(nums.size() - k + 1, nums, 0, nums.size() -1);
	}
	void swap(vector<int> & nums, int l, int r) {
		int tmp = nums[l];
		nums[l] = nums[r];
		nums[r] = tmp;
	}
	int getKth(int k, vector<int>& nums, int start, int end) {
		int pivot = nums[end];
		int left = start;
		int right = end;
		while(true) {
			while( nums[left] < pivot && left < right ) {
				++left;
			}
			while( nums[right] >=pivot && left < right ) {
				--right;
			}
			if (left == right) {
				break;
			}
			swap(nums, left, right);
		}
		swap(nums, left, end);
		if (k == left + 1) {
			return pivot;
		} else if (k < left + 1) {
			return getKth(k, nums, start, left -1);
		} else {
			return getKth(k, nums, left+1, end);
		}
	}
};

int main() {
Solution s;
return 0;
}
