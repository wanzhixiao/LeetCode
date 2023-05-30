#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std; 

class Solution {
private:
	int directions[3][2] = {{-1,1},{0,1},{1,1}};
    struct Point{
        int x,y,d;
        Point(){}
        Point(int x,int y, int d): x(x),y(y),d(d){}
    };
public:
	// bfs方法 
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        queue<pair<int,int> > q;
        
        // 在for循环外声明，若在循环内部声明会超出内存限制 
        vector<vector<int>> dis(m,vector<int>(n,-1));
		
		// 把第0列的坐标加入到数组中 
     	for (int i = 0; i < m; i++) {
     		int x = i, y = 0;
            dis[x][y] = 0;
     		q.push({x,y});
        }

     	while (!q.empty()) {
					pair<int,int> p = q.front();
                    q.pop();

					int rx = p.first, ry = p.second;
              		ans = max(ans, dis[rx][ry]);
					for (int k = 0; k < 3; k++) {
						int nx = directions[k][0] + rx;
						int ny = directions[k][1] + ry;

						if (nx >= 0 && nx < m && ny >= 0 && ny < n && (dis[nx][ny] == -1) && (grid[rx][ry] < grid[nx][ny])) {
                            dis[nx][ny] = dis[rx][ry] + 1; 
							q.push({nx,ny});
						}
					}
			}
    	return ans;
    }
    
private:
    const static int N = 1001;
    // vector<vector<int>> memo(1001,vector<int>(1001, -1));
    vector<vector<int>> memo = vector<vector<int>>(1001, vector<int>(1001, -1));
public:
    int maxMoves1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        // function<int(int,int)> dfs = [&](int i,int j) {
        //     if (j == n-1) {
        //         return 0;
        //     }
        //     if (memo[i][j] != -1) {
        //         return memo[i][j];
        //     }
        //     int res = 0;
        //     for (int k = max(0,i-1); k < min(m, i+2); k++) {
        //         if (grid[k][j + 1] > grid[i][j])
        //             res = max(res, dfs(k, j+1)+1);
        //     }
        //     memo[i][j] = res;
        //     return res;
        // };

		// 递推版本 
        vector<vector<int>> f(m,vector<int>(n,0));
        for (int j = n-2; j >= 0; j--) {
            for (int i=0; i < m; i++) {
                vector<int> row = grid[i];
                for (int k = i-1; k <= i+1; k++) {
                    if (k>=0 && k < m && grid[k][j+1] > row[j]) {
                        f[i][j] = max(f[i][j], f[k][j+1]+1);
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            ans = max(ans, f[i][0]);
        }
        return ans;
    }
};
/*
dfs版本 
class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        n,m = len(grid),len(grid[0])
        @cache
        def dfs(i,j):
            ans = 0
            if j+1 < m and grid[i][j]<grid[i][j+1]:
                ans = max(ans,dfs(i,j+1)+1)
            if i+1<n and j+1<m and grid[i][j]<grid[i+1][j+1]:
                ans = max(ans,dfs(i+1,j+1)+1)
            if i-1>=0 and j+1 < m and grid[i][j]<grid[i-1][j+1]:
                ans = max(ans,dfs(i-1,j+1)+1)
            return ans
        res = 0
        for i in range(0,n):
                res = max(res,dfs(i,0))
        return res
*/


class DATA{
public:
	// 既不能修改，又要共享
	// 类内声明 
   const static int num;
};
// 类外定义 
const int DATA::num = 100;

int main() {
	Solution s;
	vector<vector<int>> grid= {{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
	cout << s.maxMoves(grid) << endl;
	return 0;
}
