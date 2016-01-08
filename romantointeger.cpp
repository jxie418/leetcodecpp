#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
	public :
	int romanToInt(string s) {
	   map<char,int> mapping;
           mapping['I'] = 1;
           mapping['V'] = 5;
	   mapping['X'] = 10;
	   mapping['L'] = 50;
	   mapping['C'] = 100;
	   mapping['D'] = 500;
	   mapping['M'] = 1000;
	   int val = 0;
	   int num = 0;
	   for (int i = 0 ; i < s.size(); i++) {
		val = mapping[s[i]];
		if(i == s.size() -1 || mapping[s[i+1]]<= val) {
		    num+=val;
		} else {
		   num-=val;
		}
	   }
           return num;
	}
};
int main(int argv, char * argc[]) {
	Solution s;
	cout<<s.romanToInt("DXXT")<<endl;
	return 0;
}
