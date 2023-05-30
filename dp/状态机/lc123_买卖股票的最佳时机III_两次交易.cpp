#include<iostream>
#include<vector>
using namespace std;


/*
思路1： 求出所有买入和卖出的之间的收益，再取收益最大的两次交易的收益之和作为结果 
思路2：三次遍历，第一次从左往右遍历，左侧最大利润 
	第二次从右往左遍历，求右侧最大利润 
	再取两者之和最大的 的下标作为结果 
*/ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int start = prices[0];
        vector<int> vec;
        prices.push_back(0);
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i]<prices[i-1]) {
                int profit = prices[i-1] - start;
                if (profit > 0) {
                    vec.push_back(profit);
                }
            }
        }
        int largest = 0,secondest = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] >= largest) {
                secondest = largest;
                largest = vec[i];
            }
            else if (vec[i] > secondest) {
                secondest = vec[i];
            }
        }
        return secondest + largest;
    }
    
     
    int maxProfit2(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int leftmin = prices[0], rightmax = prices[n-1];
        vector<int> dp1(n,0), dp2(n,0);
        for (int i = 1; i < n; i++) {
            if (prices[i] < leftmin) {
                leftmin = prices[i];
            }
        	dp1[i] = max(dp1[i-1],prices[i]-leftmin);
        }
        for (int j = n-2; j >= 0; j--) {
            if (prices[j] > rightmax) {
                rightmax = prices[j];
            }
            dp2[j] = max(dp2[j+1],rightmax-prices[j]);
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans,dp1[i]+dp2[i]);
        }
        return ans;
    }
    
    //思路3：按照k次交易的方法来做，k=2，参考188题 
    private:
    	int f[100100][3][2];
	public: 
	    int maxProfit(vector<int>& prices) {
	        int ans = 0;
	        int n = prices.size();
	
	        memset(f,-0x3f,sizeof(f));
	        for (int i = 0; i <= n; i++) {
	            f[i][0][0] = 0;
	        }
	        for (int i = 1; i <= n; i++) {
	            for (int j = 1; j <= 2; j++) {
	                f[i][j][0] = max(f[i-1][j][0],f[i-1][j][1]+prices[i-1]);
	                f[i][j][1] = max(f[i-1][j-1][0]-prices[i-1],f[i-1][j][1]);	//j-1是因为买入不算交易次数，一次交易指的是 买入-持有-卖出三个状态 ，只算一次交易次数 
	            }
	        }
	        //7,6,4,3,1;  啥也不做， 交易一次1,2,3,4,5; 交易两次 1,2,4,2,3,5
	        return max(f[n][0][0],max(f[n][1][0],f[n][2][0]));
	    }
};

/*
ttest_case 不过
[[1,2,4,2,5,7,2,4,9,0] 
*/
int main() {
	
	return 0;
}
