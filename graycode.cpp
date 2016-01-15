#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		int size = 1 <<n;
		for (int i = 0; i < size ; i++) {
			res.push_back((i>>1)^i);
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> res =s.grayCode(4);
	for (int i = 0; i < res.size() ;i++) {
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}

