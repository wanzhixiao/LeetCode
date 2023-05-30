#include <iostream>
#include <queue>
#include<unordered_map> 
#include<algorithm>
#define N 12
using namespace std;
int maze[N][N];
int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m;

vector<vector<int>> bfs() {
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    q.push({0,0});
    unordered_map<int,int> fa;
    fa[0] = -1;
    visited[0][0] = true;
	vector<vector<int>> ans;
	
    while (!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        
        if (x == n-1 && y == m-1) {
        	break;
		}
        for (int *p : direction) {
            int nx = p[0] + x;
            int ny = p[1] + y;

            if (nx >= 0 && nx < n && ny>=0 && ny < m && !visited[nx][ny] && maze[nx][ny] == 0) {
            	int f = nx * m + ny;

  				visited[nx][ny] = true;
  				fa[f] = x*m+y;
  				q.push({nx,ny});
			}
        }
    }
    int x = n-1, y = m-1;
    int ff = m*n-1;
	while (ff != -1) {
		int x = ff/m, y = ff%m;
		ans.push_back({x,y});
		ff = fa[ff];
	}
	return ans;
}

int main() {
    // scanf("%d%d",&n,&m);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // scanf("%d ",&maze[i][j]);
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> ans =  bfs();
    for (int i = ans.size()-1; i >= 0; i--) {
    	vector<int> vec = ans[i];
    	cout << "(" << vec[0] << "," << vec[1] << ")" << endl;
	}
	return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
