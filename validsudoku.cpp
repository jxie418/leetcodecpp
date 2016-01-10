#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
	bool isValidSudoku(vector<vector<char> > & board) {
	   bool row[9][9];
	   bool col[9][9];
	   bool  dp[9][9];
	   memset(row,0, 9*9*sizeof(bool));
	   memset(col,0, 9*9*sizeof(bool));
           memset(dp, 0, 9*9*sizeof(bool));

	   for(int i = 0; i < 9 ; i++) {
		for(int j =0; j < 9; j++) {
			if(board[i][j] == '.') {
				continue;
			}
			int c = board[i][j] - '1';
		        if (row[i][c] || col[j][c] || dp[i-i %3 + j/3][c]) {
				return false;
			}
			row[i][c]= true;
			col[j][c] = true;
			dp[i- i % 3 + j / 3][c] = true;
		}
	   }
	   return true;
	}
};

int main() {
    Solution s;
    
}
