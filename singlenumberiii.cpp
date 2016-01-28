#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
vector<int> singleNumber(vector<int> & nums) {
	vector<int> res;
	int A = 0, B = 0, AXORB = 0;
	for (int i = 0 ; i < nums.size() ; i++) {
		AXORB ^=nums[i];
	}
	AXORB = (AXORB&(AXORB-1))^ AXORB;
	for (int i = 0; i < nums.size() ; i++) {
		if ((AXORB & nums[i]) == 0)
			A^=nums[i];
		else 
			B^=nums[i];
	}
	res.push_back(A);
	res.push_back(B);
	return res;
}
};

int main() {
Solution s;
return 0;
}
