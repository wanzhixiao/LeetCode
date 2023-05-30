#include<bits/stdc++.h>
using namespace std;

/*
不同路径。只能往下或往右走
思路1，dp:
    1.确定dp[i][j], 表示行为i,列为j的位置有dp[i][j]条路径
    2.确定递推方程，dp[i][j] = dp[i-1][j] + dp[i][j-1];
    3.初始化第一行 dp[0][j] = dp[0][j-1]; 第一列dp[i][0] = dp[i-1][0]
    4.遍历
        for(i = 1; i<n; i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    5.举例
    m=3,n=2;总共有3跳路径
    x x x
    x x x

思路2：DFS
    从0,0,开始搜索，当搜到m,n则路径数加1，否则回退至上一步

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1){
            return 1;
        }
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i=1;i<m;i++){
            dp[i][0] = dp[i-1][0];
        }
        for(int j=1;j<n;j++){
            dp[0][j] = dp[0][j-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths2(int m,int n){
        vector<vector<int>> result(m,vector<int>(n,-1));
        result[m-1][n-1] = 1;
        return dfs(0,0,m,n,result);
    }

    int dfs(int x,int y,int m,int n,vector<vector<int>> &result){
        if(result[x][y] != -1){
            return result[x][y];
        }
        int count = 0;
        if(x+1<m){count += dfs(x+1,y,m,n,result);}
        if(y+1<n){count += dfs(x,y+1,m,n,result);}
        result[x][y] = count;
        return count;
    }

    //不同的路径2
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0] == 1){
            return dp[0][0];
        }
        //初始化行
        dp[0][0] = 1;
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==1)
            {
                  dp[0][i] = 0;
            }
            else{
                  dp[0][i] = dp[0][i-1];
            }
        }
        //初始化列
        for(int j=1;j<m;j++){
            if(obstacleGrid[j][0]==1){
                dp[j][0] = 0;
            }
            else
            {
                dp[j][0] = dp[j-1][0];
            }
        }
        //遍历更新dp table
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else
                {
                    if(obstacleGrid[i-1][j]==1){
                        dp[i][j] = dp[i][j-1];
                    }
                    else if(obstacleGrid[i][j-1]==1){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};


int main(){
    int m = 3,n=7;
    Solution s;
    // cout << s.uniquePaths2(m,n) << endl;
    vector<vector<int> > vec = {{0,0},{1,1},{0,0}};
    cout << s.uniquePathsWithObstacles(vec) << endl;
    return 0;
}