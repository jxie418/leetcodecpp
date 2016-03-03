#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_set<string> st;
        unordered_map<char, string> mp;
        return match(str, 0, pattern, 0, st, mp);
    }
private:
    bool match(string& str, int i, string& pat, int j, unordered_set<string>& st, unordered_map<char, string>& mp) {
        int m = str.length(), n = pat.length();
        if (i == m && j == n) return true;
        if (i == m || j == n) return false;
        char c = pat[j];
        if (mp.find(c) != mp.end()) {
            string s = mp[c];
            int l = s.length();
            if (s != str.substr(i, l)) return false;
            return match(str, i + l, pat, j + 1, st, mp);
        } 
        for (int k = i; k < m; k++) {
            string s = str.substr(i, k - i + 1);
            if (st.find(s) != st.end()) continue;
            st.insert(s);
            mp[c] = s;
            if (match(str, k + 1, pat, j + 1, st, mp)) return true;
            st.erase(s);
            mp.erase(c);
        }
        return false;
    }
};





class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> d;
        unordered_map<string, bool> used;
        return match(pattern, str, d, used);
    }
    
    bool match(string pattern, string str, unordered_map<char, string> &d, unordered_map<string, bool> &used) {
        if(pattern.length() == 0 && str.length() == 0)
            return true;
        if(pattern.length() == 0 || str.length() == 0)
            return false;
            
        if(pattern.length() == 1) {
            if(d.find(pattern[0]) == d.end()) {
                if(used.find(str) == used.end())
                    return true;
                else
                    return false;
            } else {
                if(d[pattern[0]] == str)
                    return true;
                else
                    return false;
            }
        }
        
        if(d.find(pattern[0]) != d.end()) {
            if(str.find(d[pattern[0]]) != 0)
                return false;
            else {
                bool result = match(pattern.substr(1), str.substr(d[pattern[0]].length()), d, used);
                if(result)
                    return true;
            }
        } else {
            int length = str.length() - (pattern.length() - 1);
            for(int i = 1; i <= length; i++) {
                string cur = str.substr(0, i);
                d.insert(pair<char, string>(pattern[0], cur));
                used.insert(pair<string, bool>(cur, true));
                bool result = match(pattern.substr(1), str.substr(cur.length()), d, used);
                d.erase(pattern[0]);
                used.erase(cur);
                if(result)
                    return true;
            }
        }
        return false;
    }
};
