#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
class Solution {
private:
unordered_map<string,vector<int>> mp;
public:
	Solution(vector<string> words) {
		for (int i= 0; i< words.size(); ++i) {
			if(mp.find(words[i]) == mp.end()) {
				vector<int> p;
				p.push_back(i);
				mp[words[i]] = p;
			} else {
				mp[words[i]].push_back(i);
			}
		}
	}
	int distance(string wordOne, string wordTwo) {
		if (mp.find(wordOne) == mp.end() || mp.find(wordTwo) == mp.end()) {
			return INT_MAX;
		}
		int index1 =0 ,index2 = 0;
		int mindistance = INT_MAX;
		while(index1 < mp[wordOne].size() && index2 < mp[wordTwo].size()) {
			if (mp[wordOne][index1] < mp[wordTwo][index2]) {
				mindistance = min(mindistance, mp[wordTwo][index2] - mp[wordOne][index1]);
				index1++;
			} else {
				mindistance = min(mindistance, mp[wordOne][index1] - mp[wordTwo][index2]);
				index2++;
			}
		}
		return mindistance;
	}

};

int main() {
	return 0;
}


