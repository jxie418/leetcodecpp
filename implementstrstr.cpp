#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
	int strStr2(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;
		if (haystack.length() == 0)
			return -1;
                int m = haystack.length();
		int n = needle.length();

		int i = 0;
		while(i < m-n) {
		    int j = 0; 
		    while( j < n) {
			if(haystack[i+j] != needle[j]) {
				break;
			}
			j++;
		    }
		    if (j == n) {
			return i;
		    }	
		    ++i;
		} 
		return -1;
		  
	}
	vector<int> KMPpreprocessing(string s) {
		int n = s.length();
		vector<int> match(n,-1);
	        int j = -1;
		for (int i = 1; i < n; i++) {
			while(j >=0 && s[i] != s[j+1])
				j = match[j];
			if (s[i] == s[j+1])
				j++;
 			match[i] = j; 
		}
		return match;
	}
	int strStr(string haystack, string needle) {
	  if ( needle.length() == 0 ) return 0;
	  if ( haystack.length() == 0 ) return -1;
	  int m = haystack.length();
	  int n = needle.length();
	  vector<int> match = KMPpreprocessing(needle);
	  int j = -1;
	  for (int i = 0; i < m; i++ ) {
		while( j >=0 && haystack[i] != needle[j+1] ) 
			j = match[j];
                if (haystack[i] == needle[j+1])
			j++;
		if (j == n-1)
			return i - n + 1;  
	  }  
	  return -1;
	}
};



int main() {
	Solution s;
	cout<<s.strStr("Done","n")<<endl;
	cout<<"Done"<<endl;
	return 0;
}





