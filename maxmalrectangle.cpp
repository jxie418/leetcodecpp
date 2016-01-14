#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> >&matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0 ) {
			return 0;
		}
		vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(),0));
		for( int i = 0; i < matrix.size() ; i++ ) {
			for (int j = 0 ; j < matrix[0].size() ; j++ ) {
				if(matrix[i][j] == '0') {
				dp[i][j] = 0;
			} else {
				dp[i][j] = i == 0 ? 1 : dp[i-1][j] + 1;
			}
		}
		}
		int myMax = 0;
		for (int i = 0; i < matrix.size() ; i++) {
			myMax = max(myMax, maxArea(dp[i]));
		}
		return myMax;
	
	}
	int maxArea( vector<int>&height ) {
		stack<int> mystack;
		int maxArea = 0, i = 0;
		while ( i < height.size() ) {
			if (mystack.empty() || height[mystack.top()] < height[i] ) {
				mystack.push(i++);
			} else {
				int t = mystack.top();
				mystack.pop();
				maxArea = max(maxArea, height[t] * (mystack.empty()? i : i- mystack.top() -1));
			}
		}
		while (!mystack.empty()) {
			int t = mystack.top();
			mystack.pop();
			maxArea = max(maxArea, height[t] * (mystack.empty() ? i : i- mystack.top() -1));
		}
		return maxArea;
	}
};
int main() {
Solution s;
return 0;
}
