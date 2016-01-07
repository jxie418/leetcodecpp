#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
  public:
	string longestPalindrome(string s) {
	     int len = s.size();
	     int p[len][len];
	     memset(p, 0, len*len*sizeof(int));
             int maxL =0, start = 0, end = 0;
             for (int i = 0 ; i < s.size() ; i++ ) {
		for(int j = 0 ; j < i; j++) {
		   p[j][i] = (s[j] == s[i] && (i-j < 2 || p[j+1][i-1]));
		   if(p[j][i] && maxL < (i-j+1)) {
			maxL = i - j + 1;
	                start = j;
                        end = i;
		   }		
		}
                p[i][i] = 1;
             }
             return s.substr(start, end - start + 1);
	}
};


int main()
{
  Solution solution;
  string s = "abccb";
  cout<<solution.longestPalindrome(s)<<endl;
  cout<<"Hello world!"<<endl;
  return 0;
}
