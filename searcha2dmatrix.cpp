#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public :
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = matrix.size(), col = matrix[0].size(), l = 0 , r = row * col -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			int x = mid / col;
			int y = mid % col;
			if (matrix[x][y] == target) {
				return true;
			} else if (matrix[x][y] > target) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return false;
	}
};
int main() {
Solution s;
return 0;
}
