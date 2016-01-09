#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	public:
	int threeSumClosest(vector<int>&nums, int target){
	  if ( nums.size() == 0 ) {
		return 0;
	  }
	  int sum = 0;
	  int closet = INT_MAX;
	  sort(nums.begin(), nums.end());
	  for (int i = 0 ; i < nums.size() -2; i++) {
	    int j = i + 1;
	    int k = nums.size() - 1;
	    while(j < k) {
		int value = nums[i] + nums[j] + nums[k];
                int diff = abs(value - target);
	        if(closet > diff) {
	           closet = diff;
	           sum = value;
		}
                if (diff == 0) {
	           return value;
		} else if (value > target) {
	           k--;
		} else {
		   j++;
		}
	    }
	  }
          return sum;
	}
};
int main(int argc, char* argv[]){
	Solution s;
        int array[] = {1,2,3,4,5,6,7,8};
	vector<int> v(array,array + 8);
        cout<<s.threeSumClosest(v,18)<<endl;
	return 0;
}
