#include<iostream>
class Solution {
public:
	int totalNQueens(int n){
	    int count = 0;
	    int local[n];
	    memset(local,0, n*sizeof(int));
	    dfc(local,n,0,count);
	    return count;
	}
        void dfc(int local[], int n, int cur,int &count) {
		if (cur == n) {
			++count;
		} else {
			for (int i = 0; i < n ; i++) {
				local[cur] = i;
				if (isValid(local, cur)) {
				     dfc(local, n, cur + 1,count);
				}
			}
		}
	}
	bool isValid(int local[], int cur) {
		for (int i = 0; i < cur ; i++) {
			if (local[i] == local[cur] || abs(local[i] - local[cur])==cur - i) {
			return false;
			}
		}
		return true;
       }
};

int main() {
	Solution s;
        return 0;
}
