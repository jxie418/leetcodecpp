#include <iostream>
#include <string>
using namespace std;
class Solution {
	public:
	string intToRoman(int num) {
	   string symbol[] = {"M","CM", "D", "CD", "C", "XC", "L", "XL","X","IX","V","IV", "I"};
	   int  value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	   string s = "";
	   for (int i= 0; num != 0; i++) {
	      while(num>=value[i]) {
		s = s + symbol[i];
		num -=value[i];
	      }
	   }	
           return s;
	}
};
int main(int argv, char* argc[]) {
	Solution s;
	cout<< s.intToRoman(521)<<endl;
	return 0;
    
}
