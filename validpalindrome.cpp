#include<iostream>
#include<ctype.h>
#include<locale>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0, j = s.length() -1;
		while( i < j ) {
			while(i < s.length() && !isalnum(s[i])) {
				i++;
			}
			while(j >=0 && !isalnum(s[i])) {
				j--;
			}
			if (i < j && tolower(s[i]) != tolower(s[j])) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};

int main () {
	Solution s;
	cout<<s.isPalindrome("A man, a plan, a canal: Panama");
	cout<<endl;
	return 0;
}

