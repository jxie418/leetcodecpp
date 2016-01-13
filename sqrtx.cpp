#include<iostream>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if( x < 0 ) {
			return -1;
		}
		if ( x == 0 ) {
			return 0;
		}
		if ( x == 1 ) {
			return 1;
		}
		long low = 0;
		long high = x / 2 + 1;
		while( low <= high ) {
             		long mid = (low + high) / 2;
			long nq = mid * mid;
			if (nq == (long)x) {
				return mid;
			} else if (nq > (long)x){
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return (int)high;
	}
};
int main() {
	Solution s;
	cout<<s.mySqrt(9)<<endl;
	return 0;
}
