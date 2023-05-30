#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/*
��Ŀ������ÿ��Ĺ�Ʊ�۸񣬹�Ʊ���ף�����-����-���������������� ���ܹ����������Σ�����ÿ������ֻ�ܳ���һ֧��Ʊ
���룺prices = [1, 3, 2, 8, 4, 9], fee = 2
�����8
���ͣ��ܹ��ﵽ���������:  
�ڴ˴�����?prices[0] = 1
�ڴ˴����� prices[3] = 8
�ڴ˴����� prices[4] = 4
�ڴ˴����� prices[5] = 9
������:?((8 - 1) - 2) + ((9 - 4) - 2) = 8
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
