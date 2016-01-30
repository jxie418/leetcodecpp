#include<iostream>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0)
            return 0;
        if(n == 1)
            return k;
        int lastD = k * (k - 1);
        int lastS = k;
        for(int i = 2; i < n; i++) {
            int tempD = (k - 1) * (lastD + lastS);
            lastS = lastD;
            lastD = tempD;
        }
        return lastS + lastD;
    }
};

int main() {
	Solution s;
	return 0;
}
