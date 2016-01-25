#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public: 
	vector<string> summaryRanges(vector<int> &nums) {
		vector<string> res;
		int i = 0, n = nums.size();
		while( i < n ) {
			int j = 1; 
			while(i+ j < n && nums[i + j] - nums[j] == j) {
				++j;	
			}
			res.push_back(j<=1 ? to_string(nums[i]) : to_string(nums[i])+"->"+ to_string(nums[i+j-1]));
			i+=j;
		}
		return res;
	}

};

int main() {
  Solution s;
  return 0;
}

