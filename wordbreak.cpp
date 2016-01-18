#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		bool dp[s.length() + 1];
		memset(dp,0,(s.length() + 1) * sizeof(bool));
		dp[0] = true;
		for (int i = 1; i <= s.length(); i++) {
			for (int j = 0 ; j < i ; j++) {
				string tmp = s.substr(j,i-j);
				dp[i] = dp[j] && wordDict.find(tmp) != wordDict.end();
				if (dp[i])
					break; 
			}
		}
		return dp[s.length()];
	}
};

int main() {
Solution s;
return 0;
}
