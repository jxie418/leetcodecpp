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

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        int row = vec2d.size();
        for (int r = 0; r < row; r++) {
            int col = vec2d[r].size();
            for (int c = 0; c < col; c++)
                data.push_back(vec2d[r][c]);
        }
        idx = 0;
    }

    int next() {
        return data[idx++];
    }

    bool hasNext() {
        return idx < data.size();
    }
private:
    vector<int> data;
    int idx;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
