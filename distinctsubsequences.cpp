#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) { 
		int dp[s.size()+1][t.size() +1];
		memset(dp,0, (s.size() +1)* (t.size()+1)*sizeof(int));
		for (int i = 0 ; i < t.size() + 1 ; i++) {
			dp[0][i] = 0;
		}
		for (int i = 0; i < s.size() + 1; i++) {
			dp[i][0] = 1;
		}
		for (int i = 1; i < s.size() + 1; i++) {
			for (int j = 1; j < t.size() + 1; j++) {
				dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1]? dp[i-1][j-1]:0);
			}
		}
		return dp[s.size()][t.size()];
	}
};
int main() {
Solution s;
cout<<s.numDistinct("rabbbit","rabbit")<<endl;
return 0;
}
