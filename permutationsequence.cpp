#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    	bool output[n];
	memset(output,0,n*sizeof(bool));
	string buf = "";
	int res[n];
	memset(res, 0, n*sizeof(int));
	res[0] = 1;
	for (int i = 1; i < n; i++) {
		res[i] = res[i-1] * i;
	}
	for (int i = n - 1; i >=0; i--) {
		int s = 1;
		while(k  > res[i]) {
			++s;
			k = k - res[i];
		}
		for (int j = 0; j < n; j++) {
			if (j + 1 <= s && output[j]) {
				++s;
			}
		}
	        output[s-1] = true;
		buf = buf + to_string(s);
	}
	return buf;
    }
};

int main() {
	Solution s;
	cout<<s.getPermutation(3,3)<<endl;
	return 0;
}
