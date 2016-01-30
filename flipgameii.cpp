#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool canWin(string s) {
        vector<int> states = gameStates(s);
        if (states.empty()) return false;
         return spragueGrundy(states) != 0;
    }
private:
    vector<int> gameStates(string& s) {
        vector<int> states;
        int n = s.length(), c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') c++;
            if (i == n - 1 || s[i] == '-') {
                if (c >= 2) states.push_back(c);
                c = 0;
            }
        }
        return states;
    }
    int firstMissingNumber(unordered_set<int>& st) {
        int m = st.size();
        for (int i = 0; i < m; i++)
            if (!st.count(i)) return i;
        return m;
    }
    int spragueGrundy(vector<int>& states) {
        int m = *max_element(states.begin(), states.end());
        vector<int> sg(m + 1, 0);
        for (int l = 2; l <= m; l++) {
            unordered_set<int> st;
            for (int l1 = 0; l1 < l / 2; l1++) {
                int l2 = l - l1 - 2;
                st.insert(sg[l1] ^ sg[l2]);
            }
            sg[l] = firstMissingNumber(st);
        }
        int v = 0;
        for (int state : states) v ^= sg[state];
        return v;
    }
};
