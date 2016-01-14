#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& A, int target) {
		if ( A.size() == 0) {
			return false;
		}
		int L = 0 , R = A.size() - 1;
		while ( L <= R) {
			int mid = ( L + R ) / 2;
			if ( A[mid] == target ) {
				return true;
			} else {
				if ( A[mid] > A[L]) {
					if ( A[L] <= target && target <= A[mid] ) {
						R = mid - 1;
					} else {
						L = mid + 1;
					}
				} else if ( A[mid] < A[L] ) {
					if ( A[mid] <= target && target <= A[R] ) {
						L = mid + 1;
					} else {
						R = mid - 1;
					}
				} else {
					++ L;
				}
			}
		} 
		return false;
	}
};

int main() {
	Solution s;
	
	return 0;
}
