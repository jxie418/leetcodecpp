#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		if (rowIndex < 0) {
			return res;
		}
		res.push_back(1);
		for (int i = 1 ; i <= rowIndex; i++) {
				for(int j = res.size() -2; j >= 0; j--) {
					res[j+1]+=res[j];
				}
				res.push_back(1);
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> res = s.getRow(4);
	for (int i =0; i < res.size(); i++) {
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
