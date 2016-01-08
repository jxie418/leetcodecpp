#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	public:
	vector<vector<int> > threeSum(vector<int> &nums) {
	   vector<vector<int> > res;
	   if(nums.size() == 0) {
	     return res;
	   }	
	   sort(nums.begin(), nums.end());
	   for(int i = 0 ; i < nums.size(); i++) {
	      int j = i+1;
	      int t = nums.size() -1;
              while(j < t) {
	        int value = nums[i] + nums[j] + nums[t];
	        if (value == 0) {
		  vector<int> tmp;
	          tmp.push_back(nums[i]);
	          tmp.push_back(nums[j]);
		  tmp.push_back(nums[t]);
	          res.push_back(tmp);
	          j++;
	          t--;		
		} else if (value > 0) {
		       t--;
		} else {
		       j++;
		}
	      }
	   }
           return res;
	}
};
int main(int argc, char* argv[]) {
	int myints[] ={32,71,12,45,26,80,53,33};
	vector<int> myvector(myints,myints+8);
        sort(myvector.begin(), myvector.end());
	for(int i = 0; i < myvector.size(); i++) {
	  cout<< myvector[i]<<" ";
	}
	cout<<endl;
}
