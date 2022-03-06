#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string×Ö·û´® the string
     * @param s2 string×Ö·û´® the string
     * @return string×Ö·û´®
     */
    string LCS(string s1, string s2) 
	{
        
    	int len1 = s1.length(), len2 = s2.length();
    	string ans = "-1";
    	
    	if (len1 == 0 || len2 == 0)
		{
    		return ans;
		}
		
		vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
		vector<vector<int>> path(len1+1,vector<int>(len2+1,0));
		
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if(i==0 || j==0)
				{
					dp[i][j] = 0;
				}
				else //i>=1 && j>=1
				{
					if (s1[i-1] == s2[j-1])
					{
						dp[i][j] = dp[i-1][j-1]+1;
						path[i][j] = 3;
					}
					else
					{
						if (dp[i-1][j] > dp[i][j-1])
						{
							dp[i][j] = dp[i-1][j];
							path[i][j] = 2;
						}
						else
						{
							dp[i][j] = dp[i][j-1];
							path[i][j] = 1;
						}
					}
				}
			}
		}
		if (dp[len1][len2] == 0)
		{
			return ans;
		}
		ans = "";
		findPath(s1,s2,path,ans,len1,len2);
		
        return string(ans.rbegin(),ans.rend());
    }
    
    void findPath(string &s1,string &s2, vector<vector<int>> &path, string &ans,int n,int m)
    {
    	if (n==0 || m==0)
    	{
    		return;
		}
		if(path[n][m] == 3)
		{
			ans += s1[n-1];
			findPath(s1,s2,path,ans,n-1,m-1);
		}
		else if(path[n][m] == 2)
		{
			findPath(s1,s2,path,ans,n-1,m);	
		} 
		else
		{
			findPath(s1,s2,path,ans,n,m-1);
		}
	}    
};

int main()
{
	string s1,s2;
	cin >> s1 >> s2;

	Solution s;
	cout << s.LCS(s1,s2) << endl;
	 
	return 0;	
} 
