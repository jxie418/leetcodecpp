#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
  public:
    double findMedianSortedArray(vector<int>&nums1, vector<int>&nums2){
       if( nums1.size() + nums2.size() < 2 ) {
	  if ( nums1.size() == 0 && nums2.size() == 0 ) {
              return 0;
          } else if ( nums1.size() == 0 ) {
	       return nums2[0];      
          } else if ( nums2.size() == 0 ) {
               return nums1[0];
          }
       }
       int i = 0, j = 0 , m = nums1.size() + nums2.size();
       double pre = 0, last = 0;
       while( i + j <= m /2 ) {
	    pre = last;
            if ( i == nums1.size() ) {
                 last = nums2[j++];
            } else if ( j == nums2.size() ) {
		 last = nums1[i++];
            } else if (nums1[i] > nums2[j]) {
		 last = nums2[j++];
            } else {
                 last = nums1[i++];
            }
	}
        return m % 2 == 0 ? (pre + last) / 2.0 : last;

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
  cout<<"Hello world!"<<endl;
  return 0;
}
