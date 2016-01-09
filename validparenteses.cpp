#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
	public :
	bool isValid(string s) {
	    stack<char> stacks;
         for(int i = 0; i < s.length() ; i++ ) {
	    if (s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
	        stacks.push(s[i]);
	    } else {
		if ( s[i] == ')' ) {
			if (stacks.empty()) {
				return false;
			} else  {
				char c = stacks.top();
				stacks.pop();
				if ( c != '(' ) {
                                	return false;
				}
			}
		}
                if ( s[i] == '}' ) {
			if ( stacks.empty() ) {
				return false;
			} else {
				char c = stacks.top();
				stacks.pop();
				if ( c != '{' ) {
					return false;
				}
			}
                }
		if ( s[i] == ']' ) {
			if (stacks.empty()) {
				return false;
			} else {
			      char c = stacks.top();
			      stacks.pop();
			      if (c != '[') {
					return false;
			      }
			}
		   }
	      }
	   }
           return stacks.empty();
	}
};

int main() {
	Solution s;
        cout<<s.isValid("{{{{}}}")<<endl;
	cout<<s.isValid("[[]]")<<endl;
	return 0;
}
