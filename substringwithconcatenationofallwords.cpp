#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
	vector<int> findSubstring(string s , vector<string>& words) {
		vector<int> res;
		int num = words.size();
		int len = words[0].size();
		if (num == 0) {
			return res;
		}
		map<string, int> mp;
		for (int i = 0 ; i < num ; i++ ) {
			mp[words[i]]++;
		}
		int i = 0;
		while( ( i + num * len -1) < s.size() ) {
			map<string, int> mp2;
			int j = 0;
			while(j < num) {
				string subs = s.substr(i + j * len, len);
				if (mp.find(subs) == mp.end()) {
					break;
				} else {
					mp2[subs]++;
					if (mp2[subs] > mp[subs]) {
						break;
					}
					j++;
				}
			}
			if (j == num) {
				res.push_back(i);
			}
			i++;
		}
		return res;
	}
};
int main() {
   string s = "barfoothefoobarman";
   vector<string> words;
   words.push_back("foo");
   words.push_back("bar");
   Solution solution;	
   vector<int> res = solution.findSubstring(s, words);
   for ( int i = 0 ; i < res.size() ; i++ ) {
	cout<<res[i]<< " ";
   }	
   cout<<endl;
   return 0;
}


