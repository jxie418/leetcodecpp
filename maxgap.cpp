#include<vector>
using namespace std;

class Solution {

public:
int maximumGap(vector<int>& num) {
	if (num.size() < 2) return 0;  
        int maxNum = num[0];  
        int minNum = num[0];  
        for (int i = 0 ; i < num.size(); i++) {
            maxNum=max(maxNum,num[i]);  
            minNum=min(minNum,num[i]);  
        }  
        int len = (maxNum - minNum) / num.size() + 1;  
        vector<vector<int> > buckets((maxNum - minNum) / len + 1);  
        for (int j =0 ; j < num.size(); j++) {
	    int x = num[j];  
            int i = (x - minNum) / len;  
            if (buckets[i].empty()) {  
                buckets[i].reserve(2);  
                buckets[i].push_back(x);  
                buckets[i].push_back(x);  
            } else {  
                if (x < buckets[i][0]) buckets[i][0] = x;  
                if (x > buckets[i][1]) buckets[i][1] = x;  
            }  
        }  
        int gap = 0;  
        int prev = 0;  
        for (int i = 1; i < buckets.size(); i++) {  
            if (buckets[i].empty()) continue;  
            gap = max(gap, buckets[i][0] - buckets[prev][1]);  
            prev = i;  
        }  
        return gap;
}
};
int main() {
Solution s;
return 0;
}
