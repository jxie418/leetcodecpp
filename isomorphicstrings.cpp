#include<string>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
     	bool isIsomorphic(string s, string t) {
     		int len1 = s.length();
		int len2 = t.length();
		if (len1 != len2 ) {
			return false;
		}
		char M1[256];
		char M2[256];
		memset(M1, 0, sizeof(char) * 256);
		memset(M2, 0, sizeof(char) * 256);
		for (int i = 0; i < len1; i++) {
			if ( M1[s[i]] == 0 ) {
				M1[s[i]] = t[i];
			} else if ( M1[s[i]] != t[i] ) {
				return false;
			}
                        if (M2[t[i]] == 0) {
				M2[t[i]] = s[i];
			} else if (M2[t[i]] != s[i]) {
				return false;
			}
		}
		return true;
	}

};
int main() {
   Solution s;
   return 0;
}
