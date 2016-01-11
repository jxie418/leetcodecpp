#include<string>
#include<vector>
#include<map>
#include<iostream>

using namespace std;
class Solution {
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs) {
		vector<vector<string> > result;
		sort(strs.begin(), strs.end());
		map<string,vector<string> > codeToStrs;
		for (int i = 0; i < strs.size() ; i++) {
			codeToStrs[getCode(strs[i])].push_back(strs[i]);
		}
		for (map<string,vector<string> >::iterator it = codeToStrs.begin(); it!= codeToStrs.end();it++) {
			result.push_back(it->second);
		}
	        return result;
	}

        string getCode(string s) {
	   sort(s.begin(), s.end());
	   return s;
	}
};

int main() {
	Solution s;
	vector<string> str;
	str.push_back("eat");
	str.push_back("tea");
	str.push_back("tan");
	str.push_back("ate");
	str.push_back("nat");
	str.push_back("bat");
	vector<vector<string> > res = s.groupAnagrams(str);
	for (int i = 0; i < res.size() ; i++) {
	   for(int j = 0 ; j < res[i].size(); j++) {
		cout<<res[i][j]<<" ";
	   }
	   cout<<endl;
	}
	return 0;
}
