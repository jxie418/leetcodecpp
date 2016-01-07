#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
     public:
     int lengthOfLongestSubstring(string s) {
	bool dp[256];
	for(int i =0; i < 256; i++) {
             dp[i] = false;
	}
        int i = 0,j = 0, res = 0;
        while(i < s.length()) {
	   if ( !dp[s[i]] ) {
	      dp[s[i]] = true;
	   } else {
               res = max(res, i - j);
               while(s[i] != s[j]) {
	          dp[s[j++]] = false;
	       }
	       j++;
           }
           i++;	
	}
        return max(res, i-j);
     }
};


int main()
{
  Solution solution;
  string s="bbbbbbb";
  int result = solution.lengthOfLongestSubstring(s);
  cout<< result <<endl;
  cout<<"Hello world!"<<endl;
  return 0;
}
