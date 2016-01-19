#include<string>
#include<vector>
using namespace std;

class Solution {
private:
static bool compare(string &s1, string &s2) {
	return s1 + s2 > s2 + s1;
}
public:
string largestNumber(vector<int> &num) {
	vector<string> arr;
	for (int i = 0; i < num.size(); i++) {
		arr.push_back(to_string(num[i]));
	}
	sort(arr.begin(), arr.end(),compare);
	string ret;
	for (int i = 0; i < arr.size(); i++) {
		ret += arr[i];
	}
	if (ret[0] == '0' && ret.size() > 0) {
		return "0";
	}
	return ret;
}
};

int main() {
Solution s;
return 0;
}
