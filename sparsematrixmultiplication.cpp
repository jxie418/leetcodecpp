#include<iostream>
#include<vector>

class Solution {
public:
vector<vector<int> > multiply(vector<vector<int> > &A, vector<vector<int> >& B) {
	int m = A.size(), n = A[0].size(), nB = B[0].size();
	vector<vector<int> > res(m, vector<int>(B[0].size(), 0));
	for (int i = 0; i < m ; i++) {
		for (int k = 0; k < n; k++) {
			if (A[i][k] != 0) {
				for (int j = 0 ; j < n ; j++) {
					res[i][j] += A[i][k] * B[k][j];
				}	
			}
		}

	}
	return res;
	}
};

int main () {
Solution s;
return 0;
}
