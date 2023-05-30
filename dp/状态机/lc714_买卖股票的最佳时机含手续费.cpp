#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/*
题目：给定每天的股票价格，股票交易（买入-持有-卖出）含有手续费 。能够交易任意多次，但是每天手里只能持有一支股票
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:  
在此处买入?prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润:?((8 - 1) - 2) + ((9 - 4) - 2) = 8
*/
class Solution {
private:
    int f[50010][2];
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(f,0,sizeof(f));
        f[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i-1][0],f[i-1][1]+prices[i]-fee);
            f[i][1] = max(f[i-1][1],f[i-1][0]-prices[i]);
        }
        return f[n-1][0];
    }
};

int main() {
	vector<int> prices = {1, 3, 2, 8, 4, 9};
	int fee = 2;
	Solution solu; 
	cout << solu.maxProfit(prices,fee) << endl;
	return 0;
} 
