#include<iostream>
#include<vector>
#include<string.h> 
using namespace std;


/*
������Ʊ�����ʱ���������k�ʽ���
f[i][j][k]��ʾ��i�콻�״���Ϊj �����Ƿ���й�Ʊ k = 0, δ���У�k=1������ 
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
            f[i][0][0] = 0;				//��ʾ��i��0�ν����Ҳ����й�Ʊ��������� 
        } 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j][0] = max(f[i-1][j][0],f[i-1][j][1]+prices[i-1]);		//Ϊʲô���ﲻ��j-1 
                f[i][j][1] = max(f[i-1][j][1],f[i-1][j-1][0]-prices[i-1]);		//Ϊʲô������j-1? ,��ʾ��j-1�����ϲ����й�Ʊ������Ҫ����Ĳ�������������j-1 
            }
        }
        // �������n�����в��������µ��������
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
