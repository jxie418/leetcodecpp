#include<vector>
#include<iostream>

using namespace std;

class Solution {
    int m, n, L, R, T, B;
    vector<vector<bool> > visited;
public:
    int minArea(vector<vector<char> >& image, int x, int y) {
        m = image.size();
        n = image[0].size();
        visited.resize(m, vector<bool>(n, false));
        L = y;
        R = y;
        T = x;
        B = x;
        dfs(image, x, y);
        return((R-L+1)*(B-T+1));
    }
    void dfs(vector<vector<char> >& image, int x, int y) {
        if(x<T) T = x;
        if(x>B) B = x;
        if(y<L) L = y;
        if(y>R) R = y;
        if(x-1>=0 && !visited[x-1][y] && image[x-1][y]=='1') {
		visited[x-1][y]=true; 
		dfs(image, x-1, y);
	}
        if(x+1<m  && !visited[x+1][y] && image[x+1][y]=='1') {
		visited[x+1][y]=true; 
		dfs(image, x+1, y);
	}
        if(y-1>=0 && !visited[x][y-1] && image[x][y-1]=='1') {
		visited[x][y-1]=true; 
		dfs(image, x, y-1);
	}
        if(y+1<n  && !visited[x][y+1] && image[x][y+1]=='1') {
		visited[x][y+1]=true; 
		dfs(image, x, y+1);
	}
    }
};
int main() {
	Solution s;
	return 0;
}
