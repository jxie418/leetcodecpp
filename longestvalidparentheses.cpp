#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.length() == 0) {
			return 0;
		}
		int count = 0, m =0, len =0;
		for ( int i = 0 ; i < s.length() ; i++ ) {
			if (s[i] == '(') {
				++count;
				++len;
			} else if (s[i] == ')') {
				--count;
				++len;
				if (count == 0) {
				   m = max(m, len);
				} else if (count < 0) {
					count = 0;
					len = 0;
				}
			}
		}
		count = 0 ;
		len = 0 ;
		for (int i = s.length() - 1 ; i >= 0 ; i--) {
		    if (s[i] == ')') {
                                ++count;
                                ++len;
                        } else if (s[i] == '(') {
                                --count;
                                ++len;
                                if (count == 0) {
                                   m = max(m, len);
                                } else if (count < 0) {
                                        count = 0;
                                        len = 0;
                                }
                        } 
		}
		return m;
	}
};

int main() {
	Solution s;
        cout<<s.longestValidParentheses(")()())")<<endl;
	return 0;
}
