#include<iostream>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
        int ladderLength(string begin, string end, unordered_set<string>& wordList) {
		queue<string> Q;
		Q.push(begin);
		Q.push("");
		int res = 1;
		while(!Q.empty()) {
			string str = Q.front();
			Q.pop();
			if (str != "") {
				int strLen = str.length();
				for (int i = 0; i < strLen; i++) {
					char tmp = str[i];
					for (char c = 'a'; c <='z'; c++) {
						if (c == tmp) {
							continue;
						}
						str[i] = c;
						if (str == end) {
							return res +1;
						}
				                if (wordList.find(str) != wordList.end()) {
						 Q.push(str);
						 wordList.erase(str);
						}
					}
					str[i] = tmp;
				}
			} else if (!Q.empty()) {
				res++;
				Q.push("");
			}
		}
		return 0;
	}

};

int main() {
Solution s;
return 0;
}
