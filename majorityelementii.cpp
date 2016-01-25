#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int> & nums) {
		vector<int> result;
		int n1, n2;
		int c1 = 0, c2 = 0;
		for (int i = 0 ; i < nums.size() ; i++) {
			if (nums[i] == n1) {
				c1++;
			} else if (nums[i] == n2) {
				c2++;
			} else if (c1 == 0) {
				c1 = 1;
				n1 = nums[i];
			} else if (c2 == 0) {
				c2 = 1;
				n2 = nums[i];
			} else {
				c1--;
				c2--;
			}
		}
		c1 = c2 = 0;
		for (int i = 0; i < nums.size(); i++) {
			if ( nums[i] == n1 ) {
				++c1;
			} else if (nums[i] == n2) {
				++c2;
			}
		}
		if (c1*3 > nums.size())
			result.push_back(n1);
		if (c2*3 > nums.size()) 
			result.push_back(n2);
		return result; 
	}

};
int main() {
	Solution s;
	return 0;
}
