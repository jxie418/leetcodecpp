#include<string>
#include<iostream>

using namespace std;
class Solution {
public:
	int minCut(string s) {
		int dp[s.length() + 1];
		for (int i = 0; i < s.length() ; i++) {
			dp[i] = s.length() - i;
		} 
		bool table[s.length()][s.length()];
		memset(table, 0, s.length() * s.length() * sizeof(bool));
		for (int i = s.length() - 1 ; i >=0; i--) {
			for (int j = i; j < s.length() ; j++) {
				if ((s[i]==s[j]) && (j-i <=1 || table[i+1][j-1])) {
					table[i][j] = true;
					dp[i] = min( dp[i] , dp[j] + 1 );
				}
			}
		}
		return dp[0] - 1;
	}
};
int main() {
Solution s;
cout<<s.minCut("aab")<<endl;
return 0;
}

