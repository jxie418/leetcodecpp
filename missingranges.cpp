#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {



public:
    vector<string> findMissingRanges2(vector<int> A, int lower, int upper) {
    	vector<string> res;
        int pre = lower -1 , cur = 0;
	for (int i = 0; i <=nums.size(); ++i) {
		cur = i == nums.size() ? upper +1 : nums[i];
		if (cur - pre > 1) {
			res.push_back(getRanges(pre+1,curr-1));
		}
		pre = cur;
	}
	return res;
    }
    string getRanges(int from,int to) {
          return from == to ? to_string(from) : to_string(from)+"->"+to_string(to);
    }
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
