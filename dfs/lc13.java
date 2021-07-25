package dfs;

class Solution13_1 {
    public
    int get(int m){
        int res = 0;
        for(;m>0;m/=10){
            res += m%10;
        }
        return res;
    }
    public int movingCount1(int m, int n, int k) {
//        vector<vector<bool> > visited(m, vector<bool>(n, false));
//        visited[0][0] = true;
        boolean[][] visited = new boolean[m][n];
        int ans = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0&&j==0) || get(i)+get(j)>k)
                    continue;
                if(i>0){
                    visited[i][j] = visited[i][j]||visited[i-1][j];
                }
                if(j>0){
                    visited[i][j] = visited[i][j]||visited[i][j-1];
                }
                ans += visited[i][j]?1:0;
            }
        }
        return ans;
    }
};

class Solution13 {
    int result=0;
    int visited[][];

    int m;
    int n;
    int k;

    public int movingCount(int m, int n, int k) {
        this.m = m;
        this.n = n;
        this.k = k;
        visited = new int[101][101];
        dfs(0,0);

        return result;
    }

    void dfs(int i,int j){
        if(!isInBound(i,j)){//超过边界
            return;
        }
        if(visited[i][j]==1){
            return;
        }
        visited[i][j] = 1;
        this.result += 1;
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i+1,j);
        dfs(i,j-1);
    }

    boolean isInBound(int i,int j){
        if(((i>=0)&&(i<this.m)&&(j>=0)&&(j<this.n))){
            //取数的每一位并相加
            int res = 0;
            while(i>0){
                res = res + (i%10);
                i/=10;
            }
            while(j>0){
                res = res +(j%10);
                j/=10;
            }
            if(res<=k){
                return true;
            }
        }
        return false;
    }
}

public class lc13 {
}
