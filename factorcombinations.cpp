#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > getFactors(int n) {
        vector<vector<int>> results;
        vector<int> result;
        getFactorsRecur(n, results, result, 0);
        return results;
    }
    
    void getFactorsRecur(int n, vector<vector<int> > &results, vector<int> result, int last) {
        for(int i = 2; i < n; i++) {
            if(n / i >= i && i >= last && n % i == 0) {
                result.push_back(i);
                result.push_back(n / i);
                results.push_back(result);
                result.pop_back();
                getFactorsRecur(n / i, results, result, i);
                result.pop_back();
            }
        }
    }
};


