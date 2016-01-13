#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isNumber(string s){
	   if( s.length() == 0) {
		return false;
	   }
	   int i = 0;
	   while(i < s.length() && s[i] == ' ') {
		++i;
	   }
	   bool isNum = false;
	   if( i < s.length() && (s[i] == '+' || s[i] == '-')) {
		++i;
	   }
	   while(i < s.length() && s[i] > '0' && s[i] <= '9') {
  		++i;
		isNum = true;
	   }
	   if (i < s.length() && s[i] == '.') {
		++i;
		while(i < s.length() && s[i] >='0' && s[i]<='9') {
			++i;
			isNum = true;
		}
	   }
	   if (isNum && i < s.length() && s[i] == 'e') {
		isNum = false;
		++i;
		if (i < s.length() && (s[i] == '+'|| s[i] == '-')) {
			++i;
		}
		while(i < s.length() && s[i] >='0' && s[i] <='9') {
			isNum = true;
   			++i;
		}
	   }
	   if(isNum) {
		while(i < s.length() && s[i] == ' ') {
			++i;
		}
		return isNum && i == s.length();
	   }
	   return false;
	}
};

int main() {
	Solution s;
	cout<<s.isNumber("123")<<endl;
	return 0;
}
