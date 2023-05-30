#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
private:
	int direction[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
    	queue<pair<int,int>> q;
    	int m = grid.size(), n = grid[0].size();
    	q.push({0,0});
    	int cnt = 1;
    	while (!q.empty()) {
    		auto it = q.front();
    		q.pop();
    		
    		for (int i = 0; i < 8; i++) {
    			int dx = it.first + direction[i][0];
    			int dy = it.second + direction[i][1];
    			if (dx >= 0 && dx < m && dy >= 0 && dy< n) {
    				if (grid[dx][dy] == grid[it.first][it.second] + 1) {
    					q.push({dx,dy});
    					cnt++;
					}
				}
			}
		}
    	return cnt == m*n;
    }
};

int main() {
	
	vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
	Solution solu;
	cout << solu.checkValidGrid(grid) << endl;
	
	return 0;
}
