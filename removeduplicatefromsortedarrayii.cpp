#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>&A) {
		if ( A.size() == 0) {
			return 0;
		}
		int len = A.size(), pre = 1, cur = 2;
		while( cur < A.size() ) {
			if ( A[pre] == A[cur] && A[pre] == A[pre - 1] ) {
				-- len;
				++ cur;
			} else {
				++ pre;
				A[pre] = A[cur++];
			}
		}
		return len;
	
	}
};

int main() {
	Solution s;
	int num[] = {1,1,1,2,2,3};
	vector<int> v(num,num + 6);
	cout<<s.removeDuplicates(v)<<endl;
	return 0;
}
