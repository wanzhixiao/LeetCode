#include<iostream>
#include<string>
#include<vector>
using namespace std; 


/*
让字符串成为回文串的最少插入次数
输入：s = "mbadm"
输出：2
解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。

dp[i][j]比表示使得s的子串s[i:j]变成回文字符串的最少操作次数, 从外向内考虑s[i:j]
如果，s[i] == s[j]， 继续考虑s[i+1][j-1]
如果,s[i] != s[j] , 考虑将s[i]插入到j的后面，继续考虑s[i+1:j]
	或者将s[j]插入到i的签名，继续考虑s[i:j-1]

状态转移方程
	dp[i][j] = min(dp[i+1][j]+1,dp[i][j-1]+1,dp[i+1][j-1])   	s[i] == s[j]
	dp[i][j] = min(dp[i+1][j]+1,dp[i][j-1]+1)				  	s[i] != s[j]
	
	dp[i][j] = 0  if i >= j
如何初始化
	dp = 
	
	
	i==j , dp[i][j] = 0;
	i>j 不存在 
	
	
如何遍历
	for(int i=n-2;i>=0;i--)			//枚举右端点 
		for(int j=i;j<n;j++)		//枚举左端点 
		{
		}
		
	求解 dp[i][j]时，需要用到dp[i+1][j]和dp[i][j-1], dp[i+1][j-1];
	因此，需要从外往内遍历	 
*/

class Solution {
public:
    int minInsertions(string s) {
		int n = s.size();
		if(n<=1){
			return 0;
		} 
		vector<vector<int>> dp(n,vector<int>(n,0));
		for(int i=n-2;i>=0;i--){					
			for(int j=i;j<n;j++){
				if(i<j){
					if(s[i]==s[j]){
						dp[i][j] = dp[i+1][j-1];
					}
					else{
						dp[i][j] = min(dp[i+1][j]+1,dp[i][j-1]+1);
					}
				}
			}
		}
		return dp[0][n-1];
    }
};

int main(){
	string a = "bbaa";
	Solution s;
	cout << s.minInsertions(a) << endl; 
	return 0;
}
