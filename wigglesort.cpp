#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int flag = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] * flag < nums[i-1] * flag) 
                swap(nums[i], nums[i-1]);
            flag = -flag;
        }
    }
};

int main() {
Solution s;
return 0;
}
