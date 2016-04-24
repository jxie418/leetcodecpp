#include<string>
#include<unordered_map>
using namespace std;

class Solution {
	
public:
	 string minimumwindowsubstring(string s, string t) {
		string res = "";
		int minLen = s.size() + 1;
		int left = 0;
		int start =0, end = 0;
		int count =0;
		unordered_map<char, int> m;
		for (char c : t) {
			m[c]++;
		}
		
		for (int right = 0; right < s.size(); right ++) {
			if (m.find(s[right]) != m.end()) {
				m[s[right]]--;
				if (m[s[right]] >=0) {
					++count;
				}
			}
			while(count == t.size()) {
				if (minLen > right - left + 1) {
					minLen = right -left +1;
					start = left;
					end = right;
				}
				if (m.find(s[left]) != m.end()) {
					m[s[left]]++;
					if (m[s[left]] > 0) {
						--count;
					}
				}
				left++;
			}
		}
		return minLen == s.size() +1 ? "": s.substr(start, end -start +1); 
	}
};

int main() {
	Solution s;
	return 0;
}
