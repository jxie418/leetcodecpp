#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
  vector<int> res;
  int L = searchLeft(nums, target);
  int R = searchRight(nums,target);
  if (L <= R) {
	res.push_back(L);
	res.push_back(R);
  } else {
	res.push_back(-1);
	res.push_back(-1);
  }
  return res;
}
int searchLeft(vector<int> &nums, int target) {
      int L = 0 , R = nums.size() -1;
      while(L<=R) {
	   int mid = (L + R) >> 1;
	   if (nums[mid] >= target) {
		R = mid -1;
	   } else  {
		L = mid + 1;
	   }
      }
      return L;
}
int searchRight(vector<int> &nums, int target) {
	int L = 0, R = nums.size() - 1;
	while(L<=R) {
	   int mid = (L + R) >> 1;
	   if (nums[mid] <=target) {
		L = mid + 1;
	   } else {
		R = mid - 1;
	   }
	}
	return R;
}
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(8);
    v.push_back(8);
    v.push_back(10);
    vector<int> res = s.searchRange(v,8);
    for (int i = 0 ; i < res.size() ; i++) {
	cout<<res[i] <<" ";
    }
    cout<<endl;
    return 0;
}
