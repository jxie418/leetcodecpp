#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char> >& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;
		int count = 0 ;
		for (int i = 0; i < grid.size() ; i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] != '1') {
					continue;
				} else {
					++count;
					floodFill(grid, i, j);
				}
			}
		}
        	return count;
	}

	void floodFill(vector<vector<char> >& grid, int i, int j) {
		if ( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() )
			return ; 
		if ( grid[i][j] != '1' )
			return ;
 		grid[i][j] = '2';
		floodFill(grid, i - 1, j);
		floodFill(grid, i + 1, j);
		floodFill(grid, i, j - 1);
		floodFill(grid, i, j + 1);
	}
};

int main() {
	Solution s;
	return 0;
}
