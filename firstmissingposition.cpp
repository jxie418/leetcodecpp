#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int firstMissingPositive(vector<int> & nums) {
			if (nums.size() == 0) {
			    return 1;
			}
			for (int i = 0; i < nums.size(); i++) {
				while(nums[i] != i + 1) {
					if (nums[i] < 0 || nums[i] > nums.size() || nums[nums[i] -1] == nums[i]) { break; }
				int tmp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
			        nums[i] = tmp;
				}
			}
			for(int i = 0; i < nums.size(); i++) {
				if (nums[i] != i+1) {
					return i+ 1;
				}
			}
			return nums.size() + 1;
		}
};
int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	cout<<s.firstMissingPositive(nums)<<endl;
	return 0;
}
