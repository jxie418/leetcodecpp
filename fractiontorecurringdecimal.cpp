#include<string>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
string fractionToDecimal(int numerator, int denominator) {
	if ( numerator == 0 ) {
		return "0";
	}
	if ( denominator == 0 ) {
		return "";
	}
	string sb = "";
	if ( (numerator < 0)^(denominator < 0)) {
		sb +="-";
	}
	long num = (long)(numerator);
	long denom = (long)(denominator);
	num = abs(num);
	denom = abs(denom);
	long res = num / denom;
	long rem = ( num % denom ) * 10;
	sb += to_string(res);
	if (rem == 0) {
		return sb;
	}
	sb +=".";
	map<long, int> mymap;
	while ( rem != 0 ) {
		if (mymap.find(rem) != mymap.end()) {
			int len = mymap[rem];
			return sb.substr(0,len) + "("+sb.substr(len) +")";
		}
		mymap[rem] = sb.length();
		res = rem / denom;
		sb += to_string(res);
		rem = (rem % denom) * 10;
	}
	return sb;
}
};
int main() {
Solution s;
cout << s.fractionToDecimal(1,3)<<endl;
return 0;
}
