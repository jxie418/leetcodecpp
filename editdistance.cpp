#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.length();
		int len2 = word2.length();
		int dp[len1+1][len2+1];
		memset(dp,0, (len1+1)*(len2+1)*sizeof(int));
		for ( int i = 0 ; i <= word1.length() ; i++ ) {
		    for ( int j = 0; j <= word2.length() ; j++ ) {
			if (i == 0 && j == 0) {
				dp[i][j] = 0;
			} else if ( i == 0 ) {
				dp[0][j] = j;
			} else if ( j == 0 ) {
				dp[i][0] = i;
			}  else {
				if ( word1[i-1] == word2[i-1] ) {
					dp[i][j] = dp[i-1][j-1];
				} else {
					dp[i][j] =1 + min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
				}
			}
		    }
		}
		return dp[len1][len2];
	}
};
int main() {
Solution s;
cout<<s.minDistance("abc","def")<<endl;
return 0;
}
