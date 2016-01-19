#include<string>
#include<iostream>
using namespace std;

class Solution {

public:
int compareVersion(string version1, string version2) {
	int i = 0, j = 0;
	while(i < version1.size() || j < version2.size()) {
		long value1 = 0;
		long value2 = 0;
		while(i < version1.size() && version1[i] != '.') {
			value1 = value1 * 10 + (version1[i++] - '0');
		}
		i++;
		while(j < version2.size() && version2[j] != '.') {
			value2 = value2* 10 + (version2[j++] - '0');
		}
		j++;
		if ( value1 > value2 ) {
			return 1;
		} else if ( value1 < value2 ) {
			return -1;
		}
	}
	return 0;
}
};
int main() {
	Solution s;
	return 0;
}
