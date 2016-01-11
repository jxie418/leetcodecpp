#include<string> 
#include<iostream>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
	   int indexS = 0 , indexP = 0, lenS = s.length(), lenP = p.length(), preP = -1,
preS = -1;
	  while(indexS < lenS) {
		if (indexP < lenP && matchChar(p[indexP], s[indexS])) {
			++indexP;
			++indexS;
		} else if (indexP < lenP && p[indexP] == '*') {
			preS = indexS;
			preP = indexP;
			++indexP;
		} else if (preP != -1) {
			indexP = preP;
			++indexP;
			++preS;
			indexS = preS;
		} else  {
	            return false;
	        }
	  }
          while(indexP < lenP) {
		if (p[indexP] != '*') {
		    return false;
		}
		indexP++;
	  }
	  return true;
	}
	bool matchChar(char p, char s) {
	    return s == p || p == '?';
	}
};

int main() {
   Solution s;
   cout<<s.isMatch("aa","a")<<endl;
   cout<<s.isMatch("aa","aa")<<endl;
   cout<<s.isMatch("aaa","aa")<<endl;
   return 0;
}
