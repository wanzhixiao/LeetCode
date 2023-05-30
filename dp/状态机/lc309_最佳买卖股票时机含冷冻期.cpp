#include<iostream>
using namespace std;


/*
309
����: prices = [1,2,3,0,2]
���: 3 
����: ��Ӧ�Ľ���״̬Ϊ: [����, ����, �䶳��, ����, ����]

122
���룺prices = [7,1,5,3,6,4]
�����7
*/

class Solution {
public:
	//309���䶳�� 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][2] - prices[i], dp[i-1][0]);          //����
            dp[i][1] = max(dp[i-1][0]+prices[i],dp[i-1][1]);             //δ����
            dp[i][2] = dp[i-1][1];                                       //�䶳
        }
        //���ص�������û�й�Ʊ��״̬���ܻ�õ����� 
        return max(dp[n-1][1],dp[n-1][2]);
    }
    
    //122 ÿ�춼���Խ���������������� 
	int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);   //δ���й�Ʊ
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);   //���й�Ʊ
        }
        //���ص�������û�й�Ʊ��״̬���ܻ�õ����� 
        return dp[n-1][0];
    } 
};
 

int main() {
	
	return 0;
} 
