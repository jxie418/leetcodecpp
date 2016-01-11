#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
      bool canJump(vector<int> &A) {
		int canReach = 0;
		for (int i = 0; i <=canReach && i < A.size(); i++) {
			canReach = max(canReach, i+ A[i]);
		}
	        return canReach >= A.size() - 1;
      }
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	cout<<s.canJump(nums)<<endl;
	return 0;
}
