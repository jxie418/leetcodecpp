#include<iostream>
using namespace std;
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (uint32_t i = 0; i <=31; i++) {
			res |=((n >> i) & 1) <<(31 -i);
		}
		return res;
	}
};
int main() {
	Solution s;
	return 0;
}
