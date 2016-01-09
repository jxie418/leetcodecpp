#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target) {
	   	vector<vector<int> > res;
		if ( nums.size() == 0 ) {
		      return res;
		} 
                sort(nums.begin(), nums.end());
		int i = 0;
		int sameValue;
		while(i < nums.size()) {
		        int r = i + 1;
			while(r < nums.size()) {
				int j = r + 1;
				int k = nums.size() - 1;
                                while(j < k) {
				   int value = nums[i]+ nums[r] + nums[j] + nums[k];
				   if (target == value) {
				       vector<int> tmp;
		                       tmp.push_back(nums[i]);
				       tmp.push_back(nums[r]);
				       tmp.push_back(nums[j]);
				       tmp.push_back(nums[k]);
				       sameValue = nums[j];
				       do {
				 	    ++j;
				       } while(sameValue == nums[j]&& j< nums.size()); 
					sameValue = nums[k];
					do {
					    --k;
					}
					while(sameValue == nums[k] && k >= 0);
					res.push_back(tmp);			
				   } else if(value > target) {
					--k;	
				   } else {
					++j;
				   }	
				}
				sameValue = nums[r];
	                        do {
				  ++r; 
				} while(sameValue == nums[r] && r < nums.size());
			}
			sameValue = nums[i];
			do {
		         ++i; 
			} while(sameValue == nums[i] && i < nums.size());
		}
		return res; 
           
	}
};
int main () {
	Solution s;
        int nums[] = {-3,-2,-1,0,2,4,5};
	vector<int> numbers(nums,nums+7);
        vector<vector<int> > res = s.fourSum(numbers,0);
        for(int i = 0; i < res.size();i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
