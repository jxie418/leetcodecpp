#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
 	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() < 2) {
			return 0;
		}
		if (k >= prices.size()) {
			return maxProfit2(prices);
		}
		int local[k+1];
		memset(local, 0, (k+1)* sizeof(int));
		int global[k+1];
		memset(global,0,(k+1)*sizeof(int));
		for (int i = 1; i< prices.size(); i++) {
			int diff = prices[i] - prices[i-1];
			for (int j = k; j >0; j--) {
				local[j] = max(global[j-1],local[j] + diff);
				global[j] = max(global[j],local[j]);
			}
		}
		return global[k];
	}


int maxProfit2(vector<int>& prices) {
int maxProfit = 0 ;
	for ( int i = 1;i < prices.size(); i++) {
		if (prices[i] > prices[i-1]) {
			maxProfit += prices[i] - prices[i-1];
		}
	}
	return maxProfit;
}
};


int main() {
Solution s;
return 0;
}
