#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	public :
	vector<string> generateParenthesis(int n) {
	     vector<string> res;
	     helper(res, 0, 0, n, "");
	     return res;
	}
        void helper(vector<string> &res, int left, int right, int n, string str) {
		if (str.length() == 2*n) {
			res.push_back(str);
		} else if (str.length() < 2*n ) {
			if (left > right && right < n) {
				helper(res, left, right + 1, n, str + ")");
			}
			if (left < n) {
				helper(res, left + 1, right, n, str + "(");
			}
		}
	}
};
int main() {
	Solution s;
	vector<string> v = s.generateParenthesis(3);
	for (int i = 0 ; i < v.size() ; i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
