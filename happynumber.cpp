#include<string>
#include<set>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		set<int> S;
		while ( S.find(n) == S.end() ) {
			S.insert(n);
			n = getNums(n);
			if (n == 1) {
				return true;
			}
		}
		return false;
	}
	
	int getNums(int n) {
		string str = to_string(n);
		int res[str.length()];
		memset(res, 0, str.length() * sizeof(int));
		for (int i = 0; i < str.length() ; i++) {
			res[i] = str[i] - '0';
		}
		int sum = 0 ;
		for (int i = 0 ; i < str.length() ; i ++) {
			sum += res[i] * res[i];
		}		
		return sum;
	}
};


int main() {
	Solution s;
	cout<<s.isHappy(68)<<endl;
	return 0;
}

