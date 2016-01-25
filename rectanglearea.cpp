#include<iostream>
using namespace std;
class Solution {

public: 
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int res = (C - A) * (D - B) + (G - E) * (H - F);
		int A1 = max(A, E);
		int B1 = max(B, F);
		int C1 = min(C, G);
		int D1 = min(D, H);
		if (D1 <= B1 || C1 <= A1 )
			return res;
		return res - (D1 - B1) * (C1 - A1) ;
	}

};

int main() {
return 0;
}
