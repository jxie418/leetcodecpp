
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
	vector<int> slidingwindowMaxinum(vector<int> &num, int k) {
		vector<int> res;
		if (num.empty()) {
			return res;
		}	
		deque<int> q;
		for (int i = 0; i < num.size() ; ++i) {
			if (!q.empty() && q.front() + k == i) {
				q.pop_front();
			}
			while(!q.empty() && num[q.back()] < num[i]) {
				q.pop_back();
			}
			q.push_back(i);
			if (i >= k-1) {
				res.push_back(num[q.front()]);
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	return 0;
}
