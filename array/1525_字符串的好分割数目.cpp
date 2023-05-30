#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


/*
思路1 
用两个map统计，第一个map统计前半段的字符及其数量，第二个map统计后半段的字符及其数量 
两次遍历：
	第一次遍历，统计字符串s中每个字符的次数
	第二次遍历，
		++map[s2[i]]		: 前半段字符数 
		--map[s2[i]] 		：后半段字符数
		
思路2
动态规划
	left[i]表示第i个字符及其左侧有多少种字符 right[i+1]表示第i个字符右侧有多少种字符 
三次遍历
	第一次统计左侧字符数量
	第二次统计右侧字符数量
	第三次遍历每个i,判断left[i]是否等于right[i+1] 

	aacaba -> aac和aba
	
	dp[0...i] == dp[i+1...n-1]
	
	dp[i][j] = dp[i+1][j] + 1 if (s[i] not in s[i+1...j])
			 = dp[i+1][j]	  else
			 
	dp[i][j] = dp[i][j-1] + 1 if (s[j] not in s[i...j-1])
			 = dp[i][j-1]     
			 
			 
	dp[i] = dp[i-1] + 1  if (s[i] not in s[0...i-1])
		  = dp[i-1]		 else 
	
	初始化
		dp[0] = 1; 
	
	for i = 1; i < n; i++ 
		dp[i] = dp[i-1] + (cnt[s[i]] == 0 );
	
	
	for (int i = 0; i < n; i++ )
	{
		if (dp[i] == dp[n-1] - dp[i])			aac  1 1 2   dp[0] = dp[2]-dp[0] = 1 ?
	} 
 
*/

class Solution{
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_map<char,int> cnt1, cnt2;     //key:character, value: count
        for (int i = 0; i < n; i++) {
            ++cnt1[s[i]];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ++cnt2[s[i]];
            --cnt1[s[i]];
            if (cnt1[s[i]]==0) {
                cnt1.erase(s[i]);
            }
            // 左边字符数 = 右边字符数
            if (cnt2.size() == cnt1.size()) {
            	cout << s.substr(0, i) << " " << s.substr(i, s.size()-i) << endl;
                ++ans;
            }
        }
        return ans;
    }
    
    int numSplits(string s) {
        int n = s.size();
        unordered_map<char,int> cnt;     //key:character, value: count
        vector<int> left(n,0), right(n+1,0);
        left[0] = 1; right[n-1] = 1;
        cnt[s[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (cnt[s[i]] == 0) {
                ++cnt[s[i]];
                left[i] = left[i-1]+1;
            } else {
                left[i] = left[i-1];
            }
 
        } 
        cnt.clear();
        cnt[s[n-1]] = 1;
        for (int i = n-2; i >= 0; i--) {
            if (cnt[s[i]] == 0) {
            	// 这里为什么是放里面？？ 
                ++cnt[s[i]];
                right[i] = right[i+1]+1;
            } else {
                right[i] = right[i+1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] == right[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
	//string s = "acbadbaada"; 
	string s = "aacaba";
	Solution solu;
	cout << solu.numSplits(s) << endl;
	return 0;
} 
