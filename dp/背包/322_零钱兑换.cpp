#include<iostream>
#include<vector>
using namespace std;

/*
��Ǯ�һ�������һ����������coins, ��һ�����Ϊamount, �������ʹ�õ�Ǯ�Ҹ�����coins�����е��������ظ�ʹ�� 
���룺coins = [1, 2, 5], amount = 11
�����3 
���ͣ�11 = 5 + 5 + 1 

˼·��
	Ǯ�ҿ���ʹ�ã�����ȫ�������� 
	dp[i][j]��ʾʹ��[0...i]����Ʒ��ɽ��j����Ҫ��Ӳ����
	dp[i][j] = min(dp[i][j],dp[i-1][j-k*coins[i]]+k) , j >= k*coins[i]
	dp[i][j] = dp[i][j], j < k*coins[i]
	
	��ʼ��
	dp[0][0] = 0;
	dp[0][i] �ռ��������޷�ѡ���κ�Ӳ����ɽ� dp[0][j] = INT_MAX�� 
	dp[i][0] û�����壬���Ϊ0������Ӳ����� , dp[0][j] = INT_MAX�� 
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		vector<vector<int>> dp(n+1,vector<int>(amount+1,amount+1));
		dp[0][0] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= amount; j++) {		//��Ҫ��ɵ���Ϊ0,����������Ϊ0��ʱ�� 
				for (int k = 0; k  <= j/coins[i-1]; k++) {
//					cout <<"k * coins[i]==" << k * coins[i-1]<< endl;
					dp[i][j] = min(dp[i][j],dp[i-1][j-k*coins[i-1]]+k);
				}
			}
		}
		return dp[n][amount] == amount+1 ? -1 : dp[n][amount];
    }
    
    int coinChange2(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,amount+1);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= amount; j++) {		//��Ҫ��ɵ���Ϊ0,����������Ϊ0��ʱ�� 
                if (j >= coins[i-1]) {
                    dp[j] = min(dp[j-coins[i-1]] + 1,dp[j]);
                }
			}
		}

		return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

int main() {
	vector<int> conis = {186,419,83,408};
	int amount = 6249;
	Solution solu;
	
	cout << solu.coinChange(conis,amount) << endl;
	
	return 0;
} 
