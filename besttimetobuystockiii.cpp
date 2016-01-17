#include<vector>
#include<iostream>
using namespace std;

class Solution {
	public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) {
			return 0;
		}
		int len = prices.size(); 
		int profiles[len];
		memset(profiles,0,len * sizeof(int));
		int buy1 = prices[0];
		int sell2 = prices[len -1];
		int max1 = 0, max2 = 0, maxValue;
		for (int i = 0; i < len ; i++) {
			buy1 = min(buy1,prices[i]);
			max1 = max(max1,prices[i] - buy1);
			profiles[i] += max1;
			int j = len - i -1;
			sell2 = max(sell2, prices[j]);
			max2 = max(max2,sell2 - prices[j]);
			profiles[j] += max2;
		}
		for(int i = 0; i < len ; i++) {
			maxValue = max(maxValue,profiles[i]);
		}
		return maxValue;
	}
};
int main() {
Solution s;
return 0;
}
