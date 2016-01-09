#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
	public:
	 vector<string> letterCombinations(string digits){
		vector<string> res;
		if ( digits.length() == 0) {
		     return res;
		}
		string strs[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		res.push_back("");
		for (int i = 0; i < digits.length(); i++) {
			vector<string> next;
			for (int j = 0; j < res.size(); j++) {
			    string tmp = res[j];
			    if (digits[i] >='2'&& digits[i] <='9') {
				string str = strs[digits[i] - '2'];
				for (int t = 0 ; t < str.length(); t++) {
				    next.push_back(tmp + str[t]);
				}
			    }
			}
			res = next;
		}
		return res;
	}
};
int main(int argc, char * argr[]) {
	Solution s;
	vector<string> res = s.letterCombinations("584");
	for(int i = 0; i < res.size() ; i++) {
		cout<< res[i] <<endl;
	}
	return 0;
    	
}
