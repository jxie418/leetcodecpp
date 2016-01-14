#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > res;
		if ( n <= 0 || k <= 0) {
			return res;
		}
		vector<int> v;
		recurse(res, n, k, v, 1);
		return res;
	}
	void recurse(vector<vector<int> >&res, int n, int k, vector<int> &v, int start) {
		if (k == v.size()) {
			res.push_back(v);
		} else if ( v.size() < k ) {
			for ( int i = start ; i <= n; i++) {
				vector<int> tmp(v.begin(), v.end());
				tmp.push_back(i);
				recurse(res, n,k, tmp, i+1);
			}
		}
	}
};

int main() {
	Solution s;
	vector<vector<int> > res = s.combine(5,3);
	for (int i = 0 ; i< res.size() ; i++) {
	  	for(int j = 0; j < res[0].size() ; j++) {
			cout<<res[i][j] <<" ";
		}
		cout<<endl;
	}
	return 0;
}
