#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
class Solution {
public:
    void calculateCost(string s, vector<vector<int>> &cost) {
        int n = s.length();
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] != s[j]) {
                    cost[i][j] = cost[i+1][j-1] + 1;
                } else {
                    if (j-i < 2) {
                        cost[i][j] = 0;
                    } else {
                        cost[i][j] = cost[i+1][j-1];
                    }
                }
            }
        }
        return;
    }
    int palindromePartition(string s, int k) {
        //1.计算cost数组
        int n = s.length();
        vector<vector<int>> cost(n,vector<int>(n,0));
        calculateCost(s,cost);
        //2.计算以i结尾下，分割的子串为k 所需要的最少字符数
        // dp[i][k] = min(dp[i][k-1] + cost[i+1][i])  ;   j >= k-1
        // dp[i][1] = cost[0][i]
        vector<vector<int>> dp(n+1,vector<int>(k+1,n));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {	//为什么第0个不用 
            for (int j = 1; j <= k && j <= i; j++) {
                if (j == 1) {
                    dp[i][j] = cost[0][i-1];
                    continue;
                }

                for (int i0 = j-1; i0 < i; i0++) {
                    dp[i][j] = min(dp[i][j], dp[i0][j-1]+cost[i0][i-1]);
                }
            }
        }

        return dp[n][k];
    }
};

int main() {
	string s = "abc";
	int k = 2;
	Solution solu;
	cout << solu.palindromePartition(s,k) << endl;
	return 0;
}
//https://leetcode.cn/problems/palindrome-partitioning-iii/solution/shu-ju-jie-gou-he-suan-fa-dong-tai-gui-h-rzge/ 
