#include <iostream>
using namespace std;
class Solution {
    public:
	bool isPalindrom(int x) {
	   if (x < 0)
		return false;
           int k = x;
           int v = 0;
           while(k > 0) {
		v = v * 10 + k % 10;
		k /=10;
	   }
           return x == v;
        }
};


int main() {
	Solution s;
	cout << s.isPalindrom(121)<<endl;
	cout << s.isPalindrom(123)<<endl;
	cout << "Done"<<endl;
        return 0;
}
