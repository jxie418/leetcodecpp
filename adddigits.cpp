#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		if (num >= 10) {
			num = getSum(num);
			if (num >= 10) {
				return addDigits(num);	
			} else {
				return num;
			}
			
		} else {
		 	return num;
		}	
	}
	int getSum(int num) {
		int sum = 0;
		while( num > 0) {
			sum += num % 10;
			num/=10;
		}
		return sum;
	}
};

int main() {
Solution s;
cout<<s.addDigits(55)<<endl;
return 0;
}
