#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
void printlnBoard(vector<vector<string> > &res, int local[], int n) {
 vector<string> sArray;
 for(int i = 0; i < n; i++) {
	string sb;
	for(int j = 0; j < n; j++) {
	    if (local[i] == j) {
		sb = sb + "Q";
	    } else {
		sb = sb + ".";
	    }
	}
	sArray.push_back(sb);
 }
 res.push_back(sArray);
}
bool isValid(int local[], int cur) {
   for(int i = 0; i < cur ; i++) {
	if (local[i] == local[cur] || abs(local[i] - local[cur]) == cur -i) {
		return false;
	}
   }
   return true;
}
void dfsSolution(vector<vector<string> >&res, int local[], int cur, int n) {
 if (n == cur) {
	printlnBoard(res, local, n);
 } else {
		for (int i = 0; i < n; i++) {
			local[cur] = i;
		        if(isValid(local, cur)) {
				dfsSolution(res, local, cur+1, n);
			}
		}
	}
}
vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > res;
	int local[n];
	memset(local,0, n*sizeof(int));
	dfsSolution(res, local, 0, n);
	return res;
}
};


int main() {
Solution s;
return 0;
}
