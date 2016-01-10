#include <iostream>
using namespace std;
class Solution {
	public:
	string countAndSay(int n) {
		string s = "1";
		for (int i = 1; i < n; i++) {
			int count = 1;
			string next = "";
			for (int j = 1; j < s.length(); j++) {
				if (s[j-1] == s[j]) {
					++count;
				} else {
					next = next + to_string(count);
					next = next + s[j-1];
					count = 1;
				}
			}
			next = next + to_string(count);
			next = next + s[s.length() -1];
			s = next;
		}
		return s;
	}
};

int main() {
	Solution s;
	cout<<s.countAndSay(19)<<endl;
	return 0;
}
