#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
     void reverseWords(vector<char>& s) {
        if(s.length<=1) return;
        swap(s, 0, s.length-1);
        int i=0, j=1;
        
        while(j<s.size()) {
            while(j<s.size() && s[j]!=' ') {
                ++j;
            }
            swap(s, i, j-1);
            i = j+1;
            j = i+1;
        }
        
    }
    
    void swap(vector<char>& s, int i, int j) {
        while(i<j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j;
        }
    }
    void reverseWords(string &s) {
	reverse(s.begin(), s.end());
	int n = s.size(),i = 0,j = 0;
	while(i < n) {
		j = i;
		while(j<n && s[j] != ' ') {
			j++;
		}
		reverse(s.begin() +i, s.begin()+j);
		i = j+1;
	}
    }
};

