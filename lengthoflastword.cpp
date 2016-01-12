#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string str) {
		int i = str.length() -1;
		while(i>=0 && str[i] == ' ') {
			--i;
		}
		int length = 0;
		while(i >= 0 && str[i] != ' ') {
	     		++length;
	     		--i;
		}
		return length;
	}
};


int main() {
   	Solution s;
	string str = "Hello World";
	cout<< s.lengthOfLastWord(str)<<endl;
	return 0;
}
