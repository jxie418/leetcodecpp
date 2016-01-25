#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:

int maximalSquare(vector<vector<char> > & matrix) {
	if ( matrix.size() == 0 || matrix[0].size() == 0) {
		return 0;
	}
	int n = matrix.size();
	int m = matrix[0].size();
	int d[n][m];
	memset(d,0, n*m*sizeof(int));
	int area = 0;
	for (int i = 0 ; i <  n ; i++) {
		for (int j = 0 ; j < m; j++) {
			if ( i == 0 || j == 0) {
				if (matrix[i][j] == '1') {
					d[i][j] = 1;
					area = max(area, 1);
				}
			} else {
				if (matrix[i][j] == '0') {
					d[i][j] = 0;
				} else {
					d[i][j] = min(min(d[i-1][j], d[i][j-1]),d[i-1][j-1])+1;
					area = max(area, d[i][j]);
				}
			}
		}
	}
	return area * area;
}
};

int main() {
Solution s;
return 0;
}


