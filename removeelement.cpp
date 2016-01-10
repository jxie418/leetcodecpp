#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	   int removeElement(vector<int>& A, int elem) {
	   	int i = 0, j = 0, len = A.size();
		while( i < A.size() ) {
			if (A[i] == elem) {
			   ++i;
			   --len;	
			} else {
			   A[j++] = A[i++];
			}
		}
		return len;
	   }
};

int main() {
	Solution s;
	int nums [] = {1,1,2,4};
	vector<int> A(nums,nums+4);
	cout<<s.removeElement(A,1)<<endl;
	return 0;
}






