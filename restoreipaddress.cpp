#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		if  ( s.length() == 0 ) {
			return res;
		}
		recurse(res, s, 1, "");
		return res;
	}

	void recurse( vector<string>& res, string s, int step, string value ) {
		if ( step == 4 && isValid(s) ) {
			res.push_back( value + "." + s);
		} else if (step < 4 ) {
			for ( int i = 1; i <= s.length() ; i++ )  {
	                    string tmp = s.substr(0,i);
			    if (isValid(tmp)) {
				 if (step == 1) {
					recurse(res, s.substr(i), step + 1, tmp);
				 } else {
					recurse(res, s.substr(i), step + 1, value + "." + tmp);
				 }
			    }
			}
		}
	}

	bool isValid(string s) {
 		if ( s.length() == 0 || s.length() > 3 ) {
  			return false;
		}
		if ( s.length() == 1 ) {
			int value = stoi(s);
			return value >=0 && value<=9;
		}
		if ( s[0] == '0' ) {
			return false;
		}
		int value = stoi(s);
		return value > 0 && value <=255;
	}
};

int main() {
	Solution s;
	vector<string> res = s.restoreIpAddresses("25525511135");
	for (int i = 0 ; i < res.size() ; i++) {
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}
