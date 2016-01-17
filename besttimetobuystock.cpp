#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if ( prices.size() == 0 ) {
			return 0;
		}
		int maxValue = 0 ;
		int minPrices = prices[0];
		for (int i = 1; i < prices.size() ; i++) {
			minPrices = min(minPrices,prices[i]);
			maxValue = max(maxValue,prices[i] - minPrices);
		}
		return maxValue;
	}
};

int main() {
Solution s;

return 0;
}
