#include<iostream>
using namespace std;

class Solution {
public:
int trailingZeroes(int n) {
	int res = 0;
	while(n > 0) {
		res += n / 5;
		n /=5;
	}
	return res;
}
};
int main() {
Solution s;
cout<<s.trailingZeroes(543)<<endl;
return 0;
}
