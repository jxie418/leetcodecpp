#include<iostream>
#include<vector>
using namespace std;

class Solution {

public:
int calculateMinimuHP(vector<vector<int> > & dungeon) {
int m = dungeon.size();
int n = dungeon[0].size();
int dp[m][n];
memset(dp,0,m*n*sizeof(int));
for ( int i = m - 1 ; i >= 0; i-- ) {
	for ( int j = n - 1 ; j >= 0; j-- ) {
		if (i == m -1 && j== n - 1) {
			dp[i][j] = max(0 - dungeon[m-1][n-1], 0);
		} else if (i == m - 1) {
			dp[i][j] = max(dp[i][j+1] - dungeon[i][j],0);
		} else if (j == n - 1) {
			dp[i][j] = max(dp[i+1][j]- dungeon[i][j],0);
		} else {
			dp[i][j] = max(min(dp[i][j+1],dp[i+1][j])-dungeon[i][j],0);
		}
	}
}
return dp[0][0] + 1;
}
};

int main() {
Solution s;
return 0;
}
