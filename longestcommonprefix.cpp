#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
	public:
	string longestCommonPrefix(vector<string> &strs) {
	   if(strs.size() == 0) {
	     return "";
	   }	
	   string res = strs[0];
           for(int i = 1 ; i <strs.size(); i++ ) {
		int j = 0; 
		while(j < strs[i].size() && j < res.size() && res[j] == strs[i][j]) {
			j++;
		}
		res = res.substr(0,j);
	   }
	   return res;
	}
};
int main(int argv, char* argc[]) {
	Solution s;
        vector<string> strs;
	strs.push_back("abcdef");
	strs.push_back("abc");
	cout<<s.longestCommonPrefix(strs)<<endl;
	cout<<"Done"<<endl;
}
