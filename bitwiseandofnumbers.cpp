#include<iostream>

using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int count = 0;
		while( n != m ) {
			m = m >> 1;
			n = n >> 1;
			++count;
		}
		return (m<<count);
	}
};
int main() {
	Solution s;
	cout<<s.rangeBitwiseAnd(4,6)<<endl;
	return 0;
}
