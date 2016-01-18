#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int> & nums) {
		int value = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			value = value ^ nums[i];
		}
		return value;
	}
};

int main() {
Solution s;
return 0;
}
