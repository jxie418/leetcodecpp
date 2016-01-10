#include<vector>
#include<iostream>
using namespace std;

class Solution {
	public:
	int searchInsert(vector<int> &nums, int target) {
		int L = 0, R = nums.size() - 1;
		while(L <= R) {
			int mid = (L + R) >> 1;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] > target) {
				R = mid - 1;
			} else {
			        L = mid + 1;
			}
		}
		return L;
	}
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	cout<<s.searchInsert(nums, 5)<<endl;
	cout<<s.searchInsert(nums, 2)<<endl;
	cout<<s.searchInsert(nums, 7)<<endl;
	cout<<s.searchInsert(nums, 0)<<endl;
	return 0;
}
