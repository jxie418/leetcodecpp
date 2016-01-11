#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int lastReach = 0, reach = 0, step = 0;
		for (int i = 0; i <= reach && i < nums.size() ; i++) {
			if (i > lastReach) {
				lastReach = reach;
				step++;
			}
			reach = max(reach, i + nums[i]);
		}
		return step;
	}
};

int main() {
   Solution s;
   vector<int> v;
   v.push_back(2);
   v.push_back(3);
   v.push_back(1);
   v.push_back(1);
   v.push_back(4);
   cout<<s.jump(v)<<endl;
   return 0;	
}
