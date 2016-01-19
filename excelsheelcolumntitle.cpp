#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string s = "";
		while(n > 0) {
			char c = (char)((n-1) %26 + 'A');
			s = c + s;
			n = (n-1) /26;
		}
		return s;
	}

};

int main() {
Solution s;
	cout<<s.convertToTitle(87)<<endl;
return 0;
}
