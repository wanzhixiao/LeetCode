#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

/*
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit

思路1：
 dp[i][j] 表示s[0..i]能够组成t[0..j]的数目
 if s[i-1] == t[j-1]
 	dp[i][j] = dp[i-1][j-1] 		//不使用s[i], 即用s[0..i-1]组成t[0..j]
	dp[i][j] = dp[i-1][j] 			//使用s[i], 即使用s[0...i]组成 t[0..j]
 else
 	dp[i][j] = dp[i-1][j]		  //s[i] != t[j]时，只能使用s[0..i-1]组成t[0..j]
	 
初始化
	dp[i][0] = 1; dp[0][j] = 0; dp[0][0] = 1
	
思路2：
	带记忆的深度优先搜索
	递归终止条件
		j == len(t), 说明找到了一个答案，返回1
		i == len(t) && j < len(t),  说明搜索完s还没找到t, 返回0
		
	单层遍历逻辑
		int cnts = 0;
		cnts += dfs(s,t,i+1,j);			//不能使用s[i]组成t[j],继续搜索s[i+1...m), t[j...n) 
		if(s[i] == s[j]) {				//使用s[i]组成t[j],继续搜索s[i+1...m), t[j+1...n) 
			cnts += dfs(s,t,i+1,j+1);
		}
		
		返回 以s[0..i], t[0..j]的组成个数 
*/

class Solution {
private:
    map<pair<int,int>,int> mp;
	 
public:
    int numDistinct(string s, string t) {
		int m = s.length();
        int n = t.length();
        vector<vector<uint64_t>> dp(m+1,vector<uint64_t>(n+1,0));	//uint64_t整数溢出后能够自动取模 
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                if (s[i-1]==t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];		//使用第i个字符和不使用第i个字符 
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
    
    int numDistinct2(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n) {
            return 0;
        }
        return dfs(s,t,m,n,0,0);
    }
    int dfs(string &s, string &t, int m, int n, int i, int j) {
        if (mp.find(pair<int,int>(i,j)) != mp.end()) {
            return mp[pair<int,int>(i,j)];
        }
        if (j == n) {
            mp[pair<int,int>(i,j)] = 1;
            return 1;
        }
        if (i == m) {
            mp[pair<int,int>(i,j)] = 0;
            return 0;
        }
        int cnts = 0;
        cnts += dfs(s,t,m,n,i+1,j);

        //使用s的第i个字符组成t的第j个字符
        if (s[i] == t[j]) {
            cnts += dfs(s,t,m,n,i+1,j+1);
        }
        mp[pair<int,int>(i,j)] = cnts;
        return cnts;
    }
};

int main() {
	string s = "rabbbit";
	string t = "rabbit";
	Solution solu;
	cout << solu.numDistinct2(s,t) << endl;
	return 0;
} 
