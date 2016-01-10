#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
	      int search(vector<int> & nums, int target) {
		  if(nums.size() == 0) {
			return -1;
		  }
		  int l = 0, r = nums.size() -1;
		  while(l <= r) {
			int mid = (l + r) >> 1;
                        if (nums[mid] == target) {
				return mid;
			} else {
				if (nums[mid] > nums[l]) {
					if (nums[l] < target && target< nums[mid]) {
						r = mid - 1;
					} else {
						l = mid + 1;
					}
				} else if (nums[mid] < nums[l]) {
					if (nums[mid] < target && target < nums[r]) {
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				} else {
					l++;
				}
			}
		  }
		  return -1;
	      }
};
int main()  {
	Solution s;
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	cout<<s.search(nums, 6)<<endl;
	return 0;
}
