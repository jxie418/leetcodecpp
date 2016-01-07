#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
  public:
	vector<int> twoSum(vector<int>& nums, int target){
		map<int,int> mapping;
		vector<int> res;
		for(int i = 0; i < nums.size(); i++) {
                     if(mapping.find(nums[i])==mapping.end()) {
			 mapping[target-nums[i]] = i;
                     } else {
		        res.push_back(mapping[nums[i]]+1);
			res.push_back(i+1);
			return res;
                     }	
                }
		return res;
       }
};


int main()
{
  Solution solution;
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  vector<int> res = solution.twoSum(nums,5);
  for (int i = 0; i < res.size(); i++) {
	 cout<< "index of " << res[i]<<endl;
  }
  cout<<"Hello world!"<<endl;
  return 0;
}
