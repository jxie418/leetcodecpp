#include<vector>
#include<iostream>
using namespace std;

class Solution {
	public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> res;
	        if (matrix.size() == 0 || matrix[0].size() == 0) {
			return res;
		}
		int x =0, y = 0;
		int row = matrix.size();
		int col = matrix[0].size();
		while(row > 0 && col >0) {
			if (row == 1) {
				for (int i = 0; i < col ; i++) {
				    res.push_back(matrix[x][y++]);
				}
				break;
			}
		 	if (col == 1) {
				for (int i = 0; i < row ; i++ ) {
				    res.push_back(matrix[x++][y]);	
				}
				break;
			}
			for (int i = 0; i < col -1; i++) {
				res.push_back(matrix[x][y++]);
			}
			for (int i = 0; i < row - 1; i++) {
				res.push_back(matrix[x++][y]);
			}
      			for (int i = 0; i < col - 1; i++) {
				res.push_back(matrix[x][y--]);
			}
			for (int i= 0; i < row - 1; i++) {
				res.push_back(matrix[x--][y]);
			}
			row -=2;
			col -=2;
			x++;
			y++;

			
		}
		return res;
	}
};

int main() {
	Solution n;
	return 0;
}
