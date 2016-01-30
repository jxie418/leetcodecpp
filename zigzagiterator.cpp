#include<vector>
#include<iostream>

using namespace std;

class ZigzagIterator {
private:
    vector<int> &mv1, &mv2;
    vector<int>::iterator it1, it2, it;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : mv1(v1), mv2(v2) {
        it1 = v1.begin();
        it2 = v2.begin();
        it = (it1 == mv1.end()) ? it2 : it1;
    }

    int next() {
        int val = *it;
        if (it == it1) {
            ++it1;
            it = (it2 == mv2.end()) ? it1 : it2;
        } else {
            ++it2;
            it = (it1 == mv1.end()) ? it2 : it1;
        }
        return val;
    }

    bool hasNext() {
        return it1 != mv1.end() || it2 != mv2.end();
    }
};

