#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto str : strs) {
            res += to_string(str.length()) + "#" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int idx = 0, pos, size;
        while (idx < s.length()) {
            pos = s.find('#', idx);
            if (pos == string::npos) break;
            size = stoi(s.substr(idx, pos-idx));
            res.push_back(s.substr(pos+1, size));
            idx = pos + 1 + size;
        }
        return res;
    }
};
