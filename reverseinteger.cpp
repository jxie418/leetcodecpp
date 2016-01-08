#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
  public:
        int reverse(int x){
	  bool positive = x >= 0 ;
	  int max = INT_MAX / 10 ;
          int res = 0 ;
          x = abs(x);
	  while(x > 0) {
	    if (res > max) {
		return 0 ;
	    }
            res = res * 10 + x % 10;
            x /= 10;
	  } 
          return positive ? res : -res;
	} 
};


int main()
{
  Solution s;
  int i = 123;
  cout << i << endl;
  cout <<s.reverse(i)<<endl;
  cout<<"Hello world!"<<endl;
  return 0;
}
