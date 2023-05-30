#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

/*
���룺s = "rabbbit", t = "rabbit"
�����3
���ͣ�
����ͼ��ʾ, �� 3 �ֿ��Դ� s �еõ� "rabbit" �ķ�����
rabbbit
rabbbit
rabbbit

˼·1��
 dp[i][j] ��ʾs[0..i]�ܹ����t[0..j]����Ŀ
 if s[i-1] == t[j-1]
 	dp[i][j] = dp[i-1][j-1] 		//��ʹ��s[i], ����s[0..i-1]���t[0..j]
	dp[i][j] = dp[i-1][j] 			//ʹ��s[i], ��ʹ��s[0...i]��� t[0..j]
 else
 	dp[i][j] = dp[i-1][j]		  //s[i] != t[j]ʱ��ֻ��ʹ��s[0..i-1]���t[0..j]
	 
��ʼ��
	dp[i][0] = 1; dp[0][j] = 0; dp[0][0] = 1
	
˼·2��
	������������������
	�ݹ���ֹ����
		j == len(t), ˵���ҵ���һ���𰸣�����1
		i == len(t) && j < len(t),  ˵��������s��û�ҵ�t, ����0
		
	��������߼�
		int cnts = 0;
		cnts += dfs(s,t,i+1,j);			//����ʹ��s[i]���t[j],��������s[i+1...m), t[j...n) 
		if(s[i] == s[j]) {				//ʹ��s[i]���t[j],��������s[i+1...m), t[j+1...n) 
			cnts += dfs(s,t,i+1,j+1);
		}
		
		���� ��s[0..i], t[0..j]����ɸ��� 
*/

class Solution {
private:
    map<pair<int,int>,int> mp;
	 
public:
    int numDistinct(string s, string t) {
		int m = s.length();
        int n = t.length();
        vector<vector<uint64_t>> dp(m+1,vector<uint64_t>(n+1,0));	//uint64_t����������ܹ��Զ�ȡģ 
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                if (s[i-1]==t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];		//ʹ�õ�i���ַ��Ͳ�ʹ�õ�i���ַ� 
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

        //ʹ��s�ĵ�i���ַ����t�ĵ�j���ַ�
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
