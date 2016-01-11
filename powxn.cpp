#include<iostream>
using namespace std;

class Solution {
	public:
	
	double myPow(double x, int n) {
		if (n == 0) {
		   return 1;
		}
		if ( n < 0 ) {
		    n = -n;
		    x = 1 /x;
		}
	        double temp = myPow(x, n/2);
		return temp * temp *(n%2 == 0 ? 1 : x);
	}
};

int main() {
	Solution s;
	cout<<s.myPow(4,4)<<endl;
	return 0;
}
