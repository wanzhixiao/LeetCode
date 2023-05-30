

class Solution {
private:
    int direction[2][2] = {{0,1},{1,0}};
public:
	// ��ͬ��·��1 https://leetcode.cn/problems/unique-paths/
	/*
		bfs��¼ÿһ����·����
			d[x][y] = d[x-1][y] + d[x][y-1]
			d[0][0] = 1
			ע�⣺d[x+1][y] d[x][y+1] ֻ����һ�ζ��� 
	*/
	int uniquePaths(int m, int n) {
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            if (p.first == m-1 && p.second == n-1) {
                return dp[p.first][p.second];
            }
            for (int *d : direction) {
                int dx = d[0] + p.first;
                int dy = d[1] + p.second;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                	// ���ܽ�ͬһ����������� 
                    if (dp[dx][dy] == 0) {
                        q.push({dx,dy});
                    }
                    dp[dx][dy] += dp[p.first][p.second];
                    // cout << p.first << " " << p.second << " " << dp[p.first][p.second] << " " << dx << " " << dy << " " << dp[dx][dy] << endl;
                }
    
            }
        }
        return 0;
    }
    
	// ��ͬ��·��2 https://leetcode.cn/problems/unique-paths-ii/
	/*
		bfs��¼ÿһ����·����
			d[x][y] = d[x-1][y] + d[x][y-1]
			d[0][0] = 1 if obstacleGrid[0][0] == 0 
			ע�⣺
				1. obstacleGrid[x][y]==1 �ĵ㲻������� 
				2.d[x+1][y] ��d[x][y+1] ��ֻ����һ�ζ��� 
	*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0]==1) {
            return 0;
        }

        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            if (p.first == m-1 && p.second == n-1) {
                return dp[p.first][p.second];
            }
            for (int *d : direction) {
                int dx = d[0] + p.first;
                int dy = d[1] + p.second;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && obstacleGrid[dx][dy] == 0) {
                	// ���ܽ�ͬһ����������� 
                    if (dp[dx][dy] == 0) {
                        q.push({dx,dy});
                    }
                    dp[dx][dy] += dp[p.first][p.second];
                    // cout << p.first << " " << p.second << " " << dp[p.first][p.second] << " " << dx << " " << dy << " " << dp[dx][dy] << endl;
                }
            }
        }
        return 0;
    }
    
    // ��ͬ��·��2�� dfs+memo 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> result(m,vector<int>(n,-1));
        result[m-1][n-1] = obstacleGrid[m-1][n-1]==1 ? 0 : 1;
        return dfs(obstacleGrid, result, 0, 0, m, n);
    }

    int dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& result, int x, int y, int m, int n) {
        int count = 0;
        if (obstacleGrid[x][y] == 1) {
            return 0;
        }
        if (x == m-1 && y == n-1) {
            return 1;
        }
        // cout << x << " " << y << " " << result[x][y] << endl;
        if(result[x][y] != -1){
            return result[x][y];
        }

        if (x + 1 < m) {
            count += dfs(obstacleGrid,result, x+1, y, m, n);
        }
        if (y + 1 < n) {
            count += dfs(obstacleGrid,result, x, y+1, m, n);
        }
        result[x][y] = count;
        return count;
    }
};

