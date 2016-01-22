#include<utility>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
bool canFinish(int numCourses, vector<pair<int,int> >&prerequisites) {
	int len = prerequisites.size();
	if ( numCourses == 0 || len == 0 ) {
		return true;
	}
	int pCounter[numCourses];
	memset(pCounter, 0, sizeof(int) * numCourses);
	for ( int i = 0 ; i < len ; i++) {
		pCounter[prerequisites[i].first]++;
	}
        queue<int> Q;
	for (int i = 0 ; i < numCourses ; i++) {
		if ( pCounter[i] == 0 ) {
			Q.push(i);
		}
	}
	int numNoPre = Q.size();
	while(!Q.empty()) {
		int top = Q.front();
		Q.pop();
		for ( int i = 0 ; i < len ; i++) {
			if (prerequisites[i].second == top) {
				pCounter[prerequisites[i].first]--;
				if (pCounter[prerequisites[i].first] == 0) {
					numNoPre++;
					Q.push(prerequisites[i].first);
				}
			}
		}
	}
	return numNoPre == numCourses;
}
};
int main() {
Solution s;
return 0;
}
