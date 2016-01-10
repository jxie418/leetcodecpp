#include<vector>
#include<iostream>

using namespace std;
class Solution {
	public:
	int trap(vector<int>& height) {
		if (height.size() == 0) {
			return 0;
		}
		int left[height.size()];
		int right[height.size()];
		int maxL = height[0];
		for (int i = 0; i < height.size() ; i++) {
			maxL = max(maxL, height[i]);
			left[i] = maxL;
		}
		int maxR = height[height.size() -1];
		for(int i = height.size() -1; i>=0; i--) {
			maxR = max(maxR, height[i]);
			right[i] = maxR;
		}
		int m = 0;
		for (int i = 0 ; i < height.size() ; i++) {
			int area = min(left[i], right[i]) - height[i];
			if (area > 0) {
				m += area;
			}
		}
		return m;
	}
};

int main() {
    Solution s;
    vector<int> height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);
    cout<<s.trap(height)<<endl;
    return 0;
}
