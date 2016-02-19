class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x1 = INT_MAX, x2 = INT_MAX;
        for(int num : nums) {
            if(num <= x1) x1 = num;
            else if ( num <= x2 ) x2 = num;
            else return true;
        }
        return false;
    }
};

int main() {
	
	return 0;
}
