
/*
���룺n = 12
�����3 
���ͣ�12 = 4 + 4 + 4
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

    //�������ٶȸ���
    int dfs(int n, unordered_set<int> &s) {
        if (memo[n] != -1) {
            return memo[n];
        }
        //�����ȫƽ�����а��������������ֱ�ӷ���1 
        if (s.count(n)) {
            memo[n] = 1;
            return 1;
        }
        int res = 0x3f3f3f;
        for (int x : s) {
            if (n > x) {
                // //1.��¼
                memo[n - x] = dfs(n - x, s);
                // //2.
                res = min(res,dfs(n - x, s)+1);
            }
        }
        memo[n] = res;
        return res;
    }
    
    
    //bfs, ��̽��ÿ�ν�i*i+cur����У�ֱ����̽��n 
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n+1,false);
        q.push(0);
        int step = 1;

        while (!q.empty()) {
            int size = q.size();
            //����ͬһ��Ľڵ�
            for (int j = 0; j < size; j++) {
                int cur = q.front();
                q.pop();
                //����ÿ���ھӽڵ���ڽڵ�
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

    // ��̬�滮
    // dp[i]��ʾ����i������Ҫ��ƽ����������Ϊdp[i] 
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for (int i = 1; i <= n; i++) {		//���� 
            int minn = INT_MAX;
            for (int j = 1; j*j <= i; j++) {	//��Ʒ
                minn = min(minn, dp[i-j*j]);
            }
            dp[i] = minn + 1;
        }
        return dp[n];
    }
};

/*
��ȫ����
12 ���Է�Ϊ 4+4+4

       7
       / \ 
      6   3
    / \    \
   5   2    2
  / \   \    \
1    4   1    1

*/
