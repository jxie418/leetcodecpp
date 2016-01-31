#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return 0;
        }
        int maxpow3 = log10(INT_MAX) /log10(3);
        int maxpow3val = pow(3,maxpow3);
        return maxpow3val % n == 0;
    }
};
