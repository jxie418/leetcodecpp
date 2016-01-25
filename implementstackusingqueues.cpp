#include<queue>
#include<iostream>
using namespace std;

class Stack {
private:
	queue<int> que[2];
	int cur;

public:
	 Stack() {
		cur = 0;
	}
	void push(int x) {
		que[cur].push(x);
	}
	void pop(void) {
		while ( que[cur].size() > 1 ) {
			que[1 - cur].push(que[cur].front());
			que[cur].pop();
		}
		que[cur].pop();
		cur = 1 - cur;
	}
	int top(void) {
		while ( que[cur].size() > 0 ) {
			que[1-cur].push(que[cur].front());
			que[cur].pop();
		}
		cur = 1 - cur;
		return que[cur].back();
	}
	bool empty(void) {
		return que[cur].empty();
	} 
};

int main() {
return 0;
}
