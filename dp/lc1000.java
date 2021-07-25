package dp;

/*
* 石头合并
* dp[i][j] 表示合并从 第i堆到第j堆所需的最小代价
*  dp[i][j] = min(dp[i][k]+dp[k+1][j])+cost[i][j] 以k为中间结点分为两堆，分别计算两堆的最小值，再加和
*
*
*  问题，如何保证最后一次合并是k堆合并成一堆？？
*
* */


class Solution1000 {
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;

        if((n-k) % (k-1) != 0){
            return -1;
        }

        int[][] dp = new int[n][n];

        int[] presum = new int[n+1];
        for(int i=0;i<n;i++){
            presum[i+1] = presum[i]+stones[i];
            dp[i][i] = stones[i]; //只有一堆石子时，花费本身,仅仅为了k堆做铺垫
        }

        for(int len=2;len<=n;len++){//枚举区间长度
            for(int i=0;i+len-1<n;i++){//枚举左端点
                int j = i+len-1;

                dp[i][j] = dp[i][i]+dp[i+1][j];

                for(int p=i+k-1;p<j;p+=k-1){   //枚举中间结点,因为是每次合并k堆
                    dp[i][j] = Math.min(dp[i][p]+dp[p+1][j],dp[i][j]);
                }
                if((j-i) % (k-1)==0){
                    dp[i][j] += (presum[j+1]-presum[i]);
                }
            }
        }

        return dp[0][n-1]-presum[n];
    }
}

public class lc1000 {
    public static void main(String[] args) {
        int[] stones = {3,2,4,1};
        int K = 2;
        Solution1000 solu = new Solution1000();

        int res = solu.mergeStones(stones,K);

        System.out.println(res);
    }
}


/*
* class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {

        int n = stones.size();
        if((n-1)%(K-1)){
            return -1;
        }
        //DP数组
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX>>1));
        //求前缀和
        for(int i = 1;i<stones.size();i++){
            stones[i]+=stones[i-1];
        }
        for(int len = 1;len<=stones.size();len++){
            for(int i =0;i+len<=stones.size();i++){
                //初始状态，单个的代价为0
                if(len==1){
                    dp[i][i] = 0;
                    continue;
                }
                int j = i+len-1;
                //这里很重要,P+=K-1,因为中间有些状态是不能合并的
                for(int p = i;p<j;p+=K-1){
                    dp[i][j] = min(dp[i][j],dp[i][p]+dp[p+1][j]);
                }
                if((len-1)%(K-1)==0){
                    int sum = stones[j]-(i?stones[i-1]:0);
                    dp[i][j]+=sum;
                }
            }
        }
        return dp[0].back();
    }
};

作者：Gosper
链接：https://leetcode-cn.com/problems/minimum-cost-to-merge-stones/solution/dong-tai-gui-hua-by-hust_dhc-71/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
* */