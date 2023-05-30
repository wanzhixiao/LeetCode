#include<iostream>
#include<vector>
#include<string.h> 
using namespace std;


/*
买卖股票的最佳时机，最多有k笔交易
f[i][j][k]表示第i天交易次数为j 手中是否持有股票 k = 0, 未持有，k=1，持有 
*/

class Solution {
private:
    const int INF = 0x3f;
    int f[1001][110][2];
public:
    int maxProfit(int k, vector<int>& prices) {
        int ans = 0, n = prices.size();
        memset(f,-INF,sizeof(f));
        for (int i = 0; i <= n; i++) {
            f[i][0][0] = 0;				//表示第i天0次交易且不持有股票的最大收益 
        } 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j][0] = max(f[i-1][j][0],f[i-1][j][1]+prices[i-1]);		//为什么这里不是j-1 
                f[i][j][1] = max(f[i-1][j][1],f[i-1][j-1][0]-prices[i-1]);		//为什么这里是j-1? ,表示第j-1天手上不持有股票，不许要额外的操作数，所以是j-1 
            }
        }
        // 遍历求第n天所有操作次数下的最大利润
        for (int i = 0; i <= k; i++) {
            ans = max(ans,f[n][i][0]);
        }
        return ans;
    }
};

int main() {
	vector<int> prices = {2,4,1};
	int k = 2;
	Solution solu;
	cout << solu.maxProfit(k,prices) << endl;
	return 0;
} 
