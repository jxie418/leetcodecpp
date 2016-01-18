#include<string>
#include<iostream>

using namespace std;
class Solution {

public:
        vector<vector<string> > partition(string s) {
		vector<vector<string> > res;
		if ( s.length() == 0 ) {
			return res;
		}		
		vector<string> v;
		helper(res, s, v);
		return res;

	}

	void helper(vector<vector<string> > &res, string s, vector<string> &v) {
		if (s.length() == 0) {
			res.push_back(v);
		} else if (s.length() > 0) {
			for (int i = 1; i <= s.length() ; i++) {
				string tmp = s.substr(0, i);
				if (isPalindrome(tmp)) {
					vector<string> newList(v.begin(), v.end());
					newList.push_back(tmp);
					helper(res, s.substr(i), newList);
				}
			}
		}
	}


	bool isPalindrome(string s) {
		string copy(s);
		reverse(copy.begin(),copy.end());
		return copy == s;
	}
};
int main() {
Solution s;
cout<<s.minCut("aab")<<endl;
return 0;
}

