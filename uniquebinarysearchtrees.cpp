#include<iostream>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
 		int dp[n+1];
		memset(dp,0, (n+1)*sizeof(int));
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i <=n; i++) {
			for (int j = 0; j < i ; j++) {
				dp[i]+=dp[j] * dp[i-j-1];
			}
		}
		return dp[n];
	}
};

int main() {
	Solution s;
	cout<<s.numTrees(5)<<endl;
	return 0;
}
