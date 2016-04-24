#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size(), ndiff = 0, l = 0, r = 0, len = 0;
        vector<int> hash(128, 0);
        while(r<n){
            int c = s[r++];
            hash[c]++;
            if(hash[c]==1){
                ndiff++;
                while(ndiff>2){
                    int c1 = s[l++];
                    hash[c1]--;
                    if(hash[c1]==0) ndiff--;
                }
            }
            len = max(len, r-l);
        }
        return len;
    }
};
