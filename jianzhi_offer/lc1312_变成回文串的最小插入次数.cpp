#include<iostream>
#include<string>
#include<vector>
using namespace std; 


/*
���ַ�����Ϊ���Ĵ������ٲ������
���룺s = "mbadm"
�����2
���ͣ��ַ����ɱ�Ϊ "mbdadbm" ���� "mdbabdm" ��

dp[i][j]�ȱ�ʾʹ��s���Ӵ�s[i:j]��ɻ����ַ��������ٲ�������, �������ڿ���s[i:j]
�����s[i] == s[j]�� ��������s[i+1][j-1]
���,s[i] != s[j] , ���ǽ�s[i]���뵽j�ĺ��棬��������s[i+1:j]
	���߽�s[j]���뵽i��ǩ������������s[i:j-1]

״̬ת�Ʒ���
	dp[i][j] = min(dp[i+1][j]+1,dp[i][j-1]+1,dp[i+1][j-1])   	s[i] == s[j]
	dp[i][j] = min(dp[i+1][j]+1,dp[i][j-1]+1)				  	s[i] != s[j]
	
	dp[i][j] = 0  if i >= j
��γ�ʼ��
	dp = 
	
	
	i==j , dp[i][j] = 0;
	i>j ������ 
	
	
��α���
	for(int i=n-2;i>=0;i--)			//ö���Ҷ˵� 
		for(int j=i;j<n;j++)		//ö����˵� 
		{
		}
		
	��� dp[i][j]ʱ����Ҫ�õ�dp[i+1][j]��dp[i][j-1], dp[i+1][j-1];
	��ˣ���Ҫ�������ڱ���	 
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
