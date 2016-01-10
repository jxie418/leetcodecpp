#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
	      void nextPermutation(vector<int>& nums) {
		   int t = nums.size() - 1;
		   while(t > 0 && nums[t -1] >= nums[t]) {
			t --;
		   }
		   int i = t --;
		   reverse(nums, i, nums.size() -1);
		   if (t <  0) {
			return;
		   }
		   while(i < nums.size()) {
			if (nums[i] > nums[t]) {
			   swap(nums, t, i);
			   break;
			}
			i++;
		   }
	      }
	      void reverse(vector<int>& nums, int i, int j) {
	      	     while(i < j) {
			swap(nums,i++, j--);
		     }
	      }
	      void swap(vector<int> & nums, int x, int y) {
		    int tmp = nums[x];
		    nums[x] = nums[y];
		    nums[y] = tmp;
	      }
};

int main() {
	Solution s;
	vector<int> v;
 	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (int i = 0 ; i < v.size() ; i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
        s.nextPermutation(v);
	for (int i = 0; i < v.size() ; i++) {
		cout<<v[i]<<" ";
	}
        cout<<endl;
	return 0;
}




