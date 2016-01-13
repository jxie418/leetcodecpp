#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
     vector<int> plusOne(vector<int> &digits) {
	int carry = 1;
	for (int i = digits.size() - 1; i>=0; i--) {
	 	int value = digits[i] + carry;
		digits[i] = value % 10 ;
		carry = value / 10;
	}
        if (carry > 0) {
	   vector<int> res;
	   res.push_back(carry);
	   for (int i = 0 ; i < digits.size() ; i++) {
		res.push_back(digits[i]);
	   }
	   return res;
	} else {
	   return digits;
	}
     }
};

int main() {
  Solution s;
  vector<int> res;
  res.push_back(1);
  res.push_back(2);
  res.push_back(3);
  vector<int> v =s.plusOne(res);
  for (int i = 0; i < v.size() ; i++) {
	cout<<v[i]<<" ";
  } 
  cout<<endl;	
}
