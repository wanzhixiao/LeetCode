
/*
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
*/ 
class Solution {
    int memo[10001];
public:
	// dfs + memo 
    int numSquares(int n) {
        unordered_set<int> s;
        for (int i = 1; i*i <= n; i++) {
            s.insert(i*i);
        }
        memset(memo,-1,sizeof(memo));
        return dfs(n,s);
    }

    //加引用速度更快
    int dfs(int n, unordered_set<int> &s) {
        if (memo[n] != -1) {
            return memo[n];
        }
        //如果完全平方数中包含了这个数。则直接返回1 
        if (s.count(n)) {
            memo[n] = 1;
            return 1;
        }
        int res = 0x3f3f3f;
        for (int x : s) {
            if (n > x) {
                // //1.记录
                memo[n - x] = dfs(n - x, s);
                // //2.
                res = min(res,dfs(n - x, s)+1);
            }
        }
        memo[n] = res;
        return res;
    }
    
    
    //bfs, 试探，每次将i*i+cur入队列，直到试探到n 
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n+1,false);
        q.push(0);
        int step = 1;

        while (!q.empty()) {
            int size = q.size();
            //缓存同一层的节点
            for (int j = 0; j < size; j++) {
                int cur = q.front();
                q.pop();
                //遍历每个邻居节点的邻节点
                for (int i = 1; i*i + cur <= n; i++) {
                    int m = i*i+cur;
                    if (m == n) {
                        return step;
                    }
                    if (!visited[m]) {
                        visited[m] = true;
                        q.push(m);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    /*
							  0
						  /   \  \x
						 1     4  9
				1+1^2   /\1+2^2
					   2 5
					  /  /\x
					 3  6  9
					   /
					  7
	
	*/

    // 动态规划
    // dp[i]表示整数i最少需要的平方数的数量为dp[i] 
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for (int i = 1; i <= n; i++) {		//背包 
            int minn = INT_MAX;
            for (int j = 1; j*j <= i; j++) {	//物品
                minn = min(minn, dp[i-j*j]);
            }
            dp[i] = minn + 1;
        }
        return dp[n];
    }
};

/*
完全背包
12 可以分为 4+4+4

       7
       / \ 
      6   3
    / \    \
   5   2    2
  / \   \    \
1    4   1    1

*/
