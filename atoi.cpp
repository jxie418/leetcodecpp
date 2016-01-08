#include <iostream>
#include <string>
using namespace std;
class Solution{

      public: 
	int myAtoi(string str) {
             if (str.size() == 0) {
		return 0;
	     } 
             int i = 0;
             while( i < str.size() && str[i] == ' ') {
		i++;
             }
             bool n = true;
             if (str[i] == '+') {
		i++;
	     } else if (str[i] == '-') {
		i++;
		n = false;
	     }
             double value = 0;
             for (;i< str.size() && str[i] >='0' && str[i] <='9' ;i++) {
		value = value * 10 + str[i] - '0';
	     }
	     value = n ? value : -value;
             if(value > INT_MAX) {
		return INT_MAX;
	     } else if (value < INT_MIN){
	        return INT_MIN;
             } 
             return (int)value;
        }
};

int main() {
    Solution s;
    cout<<s.myAtoi("1234")<<endl;
    return 0;
}
