#include<iostream>
#include<vector>
#include<string.h> 
using namespace std; 


class Solution {
public:
	//dfs 
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, word1.size()-1, word2.size()-1);
    }

    int dfs(string word1, string word2, int i, int j) {
        if (i < 0 ) {			// i==0 
            return j+1;
        }
        if (j < 0) {		    //j==0
            return i+1;
        }
        //word1 = "", word2 = ""; 会报错 
        if (word1[i] == word2[j]) {
            return dfs(word1, word2, i-1, j-1);
        }
        return 1 + min(dfs(word1,word2,i-1,j-1),min(dfs(word1,word2,i-1,j),dfs(word1,word2,i,j-1)));
    }
    
    //动态规划
	int minDistance2(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		//初始化 
		for (int i = 0; i <= n; i++) {
			dp[0][i] = i;
		} 
		for (int i = 0; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i-1] == word2[j-1]) {
					//如果word1[i]==word2[j]， 则看word1[i], word2[j]的最短编辑距离是多少 
					dp[i][j] = dp[i-1][j-1];
				} else {
					//dp[i-1][j-1]替换， dp[i-1][j]  删除， dp[i][j-1] 插入 
					dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
				} 
			}
		}
		return dp[m][n];
    }
	 
};

int main() {
	string word1 = "horse", word2 = "ros";
	Solution solu;
	cout << solu.minDistance2(word1, word2) << endl;
	return 0;
}
