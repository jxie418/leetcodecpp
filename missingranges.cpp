#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> out;
        int curstart = lower;
 
        for (int i=0;i<n;i++) {
            if (A[i] == curstart) {
                curstart++;
            } else if (A[i] > curstart) {
                string tempout = "";
                if (A[i] == curstart+1) {
                    tempout += to_string(curstart);
                } else {
                    tempout += to_string(curstart);
                    tempout += "->";
                    tempout += to_string(A[i]-1);
                }
 
                out.push_back(tempout);
                curstart = A[i]+1;
            }
        }
 
        string tempout = "";
        if (n>0 && A[n-1] < upper-1 || n==0 && upper > lower) {
            tempout += to_string(curstart);
            tempout += "->";
            tempout += to_string(upper);
        } else if (n>0 && A[n-1] == upper-1 || n==0 && upper == lower) {
            tempout += to_string(upper);
        }
 
        if (tempout != "")
            out.push_back(tempout);
 
        return out;
    }
};
