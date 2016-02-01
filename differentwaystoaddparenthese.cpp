#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> res;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '+' 
			  ||input[i] == '-'
			  ||input[i] == '*') {
			   vector<int> left = diffWaysToCompute(input.substr(0,i));
			   vector<int> right = diffWaysToCompute(intput.substr(i+1));
			   for (int j = 0; j < left.size(); j++) {
				for (int k = 0; k < right.size(); k++) {
				    if (input[i] == '+') {
					res.push_back(left[j] + right[k]);
				    } else if (input[i] == '-') {
					res.push_back(left[j] - right[k]);
				    } else {
					res.push_back(left[j]*right[k]);
				    }
				}
			   }
			}
		}
		if (res.empty()) {
			res.push_back(atoi(input.c_str()));
		}
		return res;
	}
};


int main() {
Solution s;
return 0;
}
