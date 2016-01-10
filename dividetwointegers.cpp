#include<iostream>
using namespace std;

class Solution {
	public :
	int divide(int dividend, int divisor) {
		long a = abs((long)dividend);
		long b = abs((long)divisor);
		long value = 0;
		while(a >= b ) {
			int counter = 0;
			while( a >=(b<<counter)) {
				counter++;
			}
			value += 1 <<(counter -1);
			a -=b <<(counter -1);
		}
		if(dividend == INT_MIN && divisor == -1) {
		     return INT_MAX;
		}
		return (int) value * ((dividend > 0 && divisor> 0) || (dividend <0 && divisor <0) ? 1 : -1);
	}
};

int main() {
	Solution s;
	cout<<s.divide(10, 2)<<endl;
        cout<<s.divide(1000,-56)<<endl;
	return 0;
}
