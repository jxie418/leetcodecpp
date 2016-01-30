#include<vector>
#include<iostream>
using namespace std;
class Vector2D {
public:
    Vector2D(vector<vector<int> >& vec2d) {
        row = vec2d.begin();
        end = vec2d.end();
        while(row != end) {
            if((*row).size() > 0) {
                col = (*row).begin();
                break;
            }
            row++;
        }
    }

    int next() {
        int lastValue = *col;
        col++;
        return lastValue;
    }

    bool hasNext() {
        if(row == end)
            return false;
        if(col != (*row).end()) {
            return true;
        } else {
            while(row != end) {
                row++;
                if(row != end && (*row).size() != 0) {
                    col = (*row).begin();
                    return true;
                }
            }
            return false;
        }
    }
    
private:
    vector<vector<int> >::iterator row, end;
    vector<int>::iterator col;
};


