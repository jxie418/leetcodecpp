#include<unordered_map>
#include<string>

using namespace std;


class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> d;
        for(auto i : s) {
            if(d.find(i) != d.end())
                d[i]++;
            else
                d.insert(pair<char, int>(i, 1));
        }
        
        bool already = false;
        for(auto i = d.begin(); i != d.end(); i++) {
            if(i->second % 2 != 0) {
                if(already)
                    return false;
                else
                    already = true;
            }
        }
        return true;
    }
};
