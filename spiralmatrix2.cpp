#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
     vector<vector<int> > generateMatrix(int n) {
     	vector<vector<int> > res(n, vector<int>(n,0));
	int start = 1;
	int x = 0, y = 0;
	for (int i = n; i > 0 ; i -= 2 ) {
		if (i == 1) {
		   res[x][y] = start++;
		}
		for ( int j = 0 ; j < i - 1 ; j++) {
		   res[x][y++] = start++;
		}
		for ( int j = 0 ; j < i - 1 ; j++) {
		   res[x++][y] = start++;
		}
		for ( int j = 0 ; j < i - 1 ; j++ ) {
		   res[x][y--] = start++;
		}
		for( int j = 0 ; j < i - 1 ; j++) {
		   res[x--][y] = start++;
		}
		x++;
		y++;
	}
	return res;
     }
};
int main() {
 	Solution s;
	vector<vector<int> > res = s.generateMatrix(4);
	for (int i = 0 ; i < res.size(); i++ ) {
		for (int j ; j < res[i].size(); j++) {
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
