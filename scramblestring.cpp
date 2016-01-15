#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if ( s1.length() == 0 ) {
			return s2.length() == 0;
		}
		if ( s2.length() == 0 ) {
			return false;
		} 
		if ( s1.length() != s2.length() ) {
			return false;
		}
		if (s1 == s2) {
			return true;
		}
		int dp[256];
		memset(dp, 0, 256 * sizeof(int));
		for ( int i = 0 ; i < s1.length() ; i++ ) {
			++dp[s1[i]];
			--dp[s2[i]];
		}
		for ( int i = 0; i < 256 ; i++) {
			if (dp[i] != 0) {
				return false;
			} 
		}
		for ( int i = 1 ; i < s1.length() ; i++) {
			string s11 = s1.substr(0,i);
			string s12 = s1.substr(i);
			string s21 = s2.substr(0,i);
			string s22 = s2.substr(i);
			if ( isScramble(s11, s21) && isScramble(s12,s22)) {
				return true;
			}
			s21 = s2.substr(0, s1.length() - i);
			s22 = s2.substr(s1.length() - i);
			if (isScramble(s11, s22) && isScramble(s12,s21)) {
				return true;
			}
		}
		return false;
	}

};

int main() {
	Solution s;
	cout<<s.isScramble("rgtae","great")<<endl;
	return 0;
}
