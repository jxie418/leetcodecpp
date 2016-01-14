#include<vector>
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	int largetRectangleArea(vector<int>& height) {
		stack<int> mystack;
		int maxArea = 0, i = 0;
		while( i < height.size()) {
			if ( mystack.empty() || height[mystack.top()] < height[i] ) {
				mystack.push(i++);
			} else {
				int t = mystack.top();
				mystack.pop();
				maxArea = max(maxArea, height[t] * (mystack.empty()?i:i-mystack.top() - 1));
			}
	}
			while ( !mystack.empty() ) {
				int t = mystack.top();
				mystack.pop();
				maxArea = max(maxArea, height[t] * (mystack.empty()?i:i-mystack.top() -1));
			}
			return maxArea;
		}
};

int main() {
	Solution s;
	int nums[] = {2,1,5,6,2,3};
	vector<int> v(nums, nums+6);
	cout<<s.largetRectangleArea(v)<<endl;
	return 0;
}
