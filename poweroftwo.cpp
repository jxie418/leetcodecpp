#include<iostream>
using namespace std;

class Solution {
public:
bool isPowerOfTwo(int n) {
if  ( n <=0 ) {
	return false;
}
while(n > 2) {
	int i = n >> 1;
	int t = i << 1;
	if (n - t != 0) {
		return false;
	}
	n = n >> 1;
}
return true;
}
};

int main() {
Solution s;
cout<<s.isPowerOfTwo(4)<<endl;
return 0;
}
