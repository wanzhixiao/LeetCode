#include<iostream>
#include<vector>
#include<string> 
using namespace std;

class Solution {
public:
	vector<vector<string>> result;
	
    vector<vector<string>> partition(string s) 
	{
		int len = s.length();
		
		vector<vector<bool>> dp(len,vector<bool>(len,false));
		
		for(int i=len-1;i>=0;i--)
		{
			for(int j=i;j<len;j++)
			{
				
				if(s[i]!=s[j])
				{
					dp[i][j] = false;
				}
				else
				{
					if(j-i<2)
					{
						dp[i][j] = true;	
					} 
					else
					{
						dp[i][j] = dp[i+1][j-1];
					}	
				}
			}	
		} 
		
		vector<string> path;
		backtracking1(s,path,dp,0,len);
		return result;
    }
    
    void backtracking1(string &s,vector<string> &path, 
					vector<vector<bool>> &dp,int i, int n)
    {
    	if(i==n)
    	{
    		result.push_back(path);
    		return;
		}
		
		for(int j=i;j<n;j++)
		{
			if(!dp[i][j])	//横向参试下一个切分点j i...j 
			{	
				continue;
			}
			string str = s.substr(i,j-i+1);	
			path.push_back(str); //从下一个切分点继续dfs 
			backtracking1(s,path,dp,j+1,n);
			path.pop_back();
		}
	}
    
    void backtracking(string &s,vector<string> &path,int i, int n)
    {
    	if(i==n)
    	{
    		result.push_back(path);
    		return;
		}
		for(int j=i;j<n;j++)
		{
			if(!check(s,i,j))	//横向参试下一个切分点j i...j 
			{	
				continue;
			}
			string str = s.substr(i,j-i+1);	
			path.push_back(str); //从下一个切分点继续dfs 
			backtracking(s,path,j+1,n);
			path.pop_back();
		}
	}
	
	bool check(string &s, int left, int right)
	{
		while(left < right)
		{
			if(s[left]!=s[right])
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};

int main()
{
	Solution solu;
	string s = "efe";
	vector<vector<string>> result = solu.partition(s);
	
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

