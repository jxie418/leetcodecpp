#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		for (int i = 0 ; i < numRows ; i++ ) {
			vector<int> tmp;
			tmp.push_back(1);
			if ( i > 0 ) {
				for (int j = 0 ; j < res[i-1].size() -1; j++) {
					tmp.push_back(res[i-1][j] + res[i-1][j+1]);
				}
				tmp.push_back(1);
			}
			res.push_back(tmp);
		}
		return res;
	}

};
int main() {
	Solution s;
	vector<vector<int> > res = s.generate(5);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout<<res[i][j]<<" ";
	}
	cout<<endl;
	}
	return 0;
}
