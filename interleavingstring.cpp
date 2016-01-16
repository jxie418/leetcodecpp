#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) {
			return false;
		}
		bool dp[s1.size() + 1][s2.size() + 1];
		memset(dp,0, (s1.size() +1)*(s2.size() +1)*sizeof(bool));
		dp[0][0] = true;
		for (int i = 0 ; i <= s1.size() ; i++) {
			for (int j = 0; j <= s2.size() ; j++) {
				if ( i == 0 && j == 0) {
					dp[0][0] = true;
				} else if ( i == 0 ) {
					dp[i][j] = s2[j-1] == s3[j-1] && dp[i][j-1];
				} else if ( j == 0 ) {
					dp[i][j] = s1[i-1] == s3[i-1] && dp[i-1][j];
				} else {
					dp[i][j] = ((s1[i-1] == s3[i+j-1])&& dp[i-1][j])||((s2[j-1]==s3[i+j-1]&&dp[i][j-1]));
				}
			}
		}
		return dp[s1.size()][s2.size()];
	}
};
int main() {
	Solution s;
	cout<<s.isInterleave("aabcc","dbbca","aadbbcbcac")<<endl;
	return 0;
}
