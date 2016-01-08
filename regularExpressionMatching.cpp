#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
	   if (p.size() == 0) {
		return s.size() == 0;
	   }	
           if(p.size() == 1 || p[1] != '*') {
		if (s.size() < 1 || (p[0] != '.' && p[0] != s[0])) {
			return false;
		}	
                return isMatch(s.substr(1), p.substr(1));
	   } else {
	       int len = s.size();
	       int i = -1;
               while(i < len && (i < 0 || p[0] == '.' || p[0] == s[i])) {
		    if(isMatch(s.substr(i+1),p.substr(2))) {
			return true;
		    }	
                    i++;
	       }	
           }
           return false;
	}
};

int main() {
	Solution s;
	cout << s.isMatch("aa","a")<<endl;
	cout << s.isMatch("aa","aa")<<endl;
	cout << s.isMatch("aaa","aa")<<endl;
	cout << s.isMatch("aa","a*")<<endl;
	cout << s.isMatch("aab","c*a*b")<<endl;
	return 0;
}
