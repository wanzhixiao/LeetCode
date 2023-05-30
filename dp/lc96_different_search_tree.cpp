#include<bits/stdc++.h>
using namespace std;

/*
不同的二叉搜索树
i           0   1   2   3
dp[i]       0   1   2   5

dp[i] = dp[i] + dp[j]*dp[i-j-1]


i = 1 dp[i] = 1 dp[0] = 1 dp[0] = 1  ,dp的下标i，表示树节点数量为i下的二叉树种数
i = 2 dp[i] = 1 dp[0] = 1 dp[1] = 1
i = 2 dp[i] = 2 dp[1] = 1 dp[0] = 1
i = 3 dp[i] = 2 dp[0] = 1 dp[2] = 2
i = 3 dp[i] = 3 dp[1] = 1 dp[1] = 1
i = 3 dp[i] = 5 dp[2] = 2 dp[0] = 1
i = 4 dp[i] = 5 dp[0] = 1 dp[3] = 5
i = 4 dp[i] = 7 dp[1] = 1 dp[2] = 2
i = 4 dp[i] = 9 dp[2] = 2 dp[1] = 1
i = 4 dp[i] = 14 dp[3] = 5 dp[0] = 1
14

枚举子树节点数量
    左子树的二叉搜索树种数 * 右子树的二叉搜索树种数
    左子树节点数 = 树中总节点数-右子树节点数-1
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);

        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] = dp[i] + dp[i-j]*dp[j-1];
            }
        }
        return dp[n];
    }

    int numTrees2(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=0;j<i;j++){       //是j<i还是j<=i, j<i表示，子树中的节点数小于全部树节点数
                dp[i] = dp[i] + dp[j]*dp[i-j-1];
                cout << "i = "<< i << " dp[i] = " << dp[i] << " dp[" << j << "] = " << dp[j] << " dp[" << i-j-1 << "] = " << dp[i-j-1] << endl; 
            }
            
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.numTrees2(4) << endl;
    return 0;
}