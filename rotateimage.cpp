#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
	int m = matrix.size();
	for (int i = 0; i < (m>>1) ; i++) {
		for (int j = i ; j < m - i -1; j++) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[m-j-1][i];
			matrix[m-j-1][i] = matrix[m-i-1][m-j-1];
			matrix[m-i-1][m-j-1] = matrix[j][m-i-1];
			matrix[j][m-i-1] = tmp;
		}
	}
    }
};
int main() {
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	vector<int> v2;
	v2.push_back(3);
        v2.push_back(4);
	vector<vector<int> > matrix;
	matrix.push_back(v);
	matrix.push_back(v2);
	for (int i = 0 ; i < matrix.size() ; i++) {
		for(int j = 0; j < matrix[i].size() ; j++) {
			cout<<matrix[i][j] <<" ";
		}
                cout<<endl;
	}
	s.rotate(matrix);
	for (int i = 0 ; i < matrix.size() ; i++) {
                for(int j = 0; j < matrix[i].size() ; j++) {
                        cout<<matrix[i][j] <<" ";
                }
                cout<<endl;
        }
        return 0;
}
