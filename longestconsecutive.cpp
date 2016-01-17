#include<set>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
int longestConsecutive(vector<int> &num) {
	if (num.size() == 0) {
		return 0;
	}
	set<int> myset(num.begin(),num.end());
	int maxValue = 1;
	for (int i = 0; i < num.size() ; i++) {
		if(myset.find(num[i]) != myset.end()) {
			int left = num[i] - 1;
			int right = num[i] + 1;
			int cout = 1;
			while(myset.find(left) != myset.end()) {
				++cout;
				myset.erase(left--);
			}
			while(myset.find(right) != myset.end()) {
				++cout;
				myset.erase(right++);
			}
			maxValue = max(maxValue,cout);
		}
		
	}
	return maxValue;
}
};
int main() {
Solution s;
return 0;
}
