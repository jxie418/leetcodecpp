#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public : 
	   int removeDuplicates(vector<int> & nums) {
	    if(nums.size() == 0) {
		return 0;		
	    }
	    int pre = 0, cur = 1, len = nums.size();
	    
	    while(cur < nums.size()) {
		if (nums[cur] == nums[pre]) {
			++cur;
			--len;
		}else {
			++pre;
			nums[pre] = nums[cur++];
		}	
	    }
	    return len;
	  }
};
int main( int argv, char* argc[] ) {
	Solution s;
	int t[] = {1,1,2};
        vector<int> nums(t,t+3);
	for (int i = 0; i < nums.size(); i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	int size = s.removeDuplicates(nums);
	for (int i = 0; i < size; i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	return 0;
}
