#include<vector>
#include<iostream>
using namespace std;
class TwoSum {
    private:
        std::vector<int> v;
    public:
void add(int a) {
    v.push_back(a);
}

bool find(int x) {
    int a, b;
    for(auto it = v.begin(); it != v.end(); ++it) {
        a = *it;
        b = x - a;
        auto iter = std::find(v.begin(), v.end(), b);
        if(iter != v.end() && iter != it)
            return true;
    }
    return false;
}
};
