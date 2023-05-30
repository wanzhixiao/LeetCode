#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

/*
单词拆分

1. 暴力解法， 滑动窗口匹配

2. dp + hashset

3. dp + 字符串hash 


dp方法：
	把wordDict中的每个单词存到hashset中 

dp[i]表示s[0...i-1]是否能被空格拆分成若干个字典中出现的单词
s[0...i-1] = s[0...j-1] + s[j...i-1];  判断s[0...j-1], s[j...i-1]是否出现在字典中

dp[0] = true;       //空串出现在字典中
    dp[i] = dp[j] & find(wordDict.begin(), wordDict.end(), s[j...i-1]) !- wordDict.end()
    dp[i] = true;
    break;

*/ 

class Solution {
private:
    typedef unsigned long long ULL;
    const int x = 13331;
    ULL H[305];
    ULL X[305];


    void Hash(string s) {
        H[0] = s[0];
        X[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            H[i] = H[i-1]*x + s[i];
            X[i] = X[i-1]*x;
        }
    }

    ULL getHash(string &s, int left, int right) {
        if (left == 0) {
            return H[right];
        }
        return H[right] - H[left-1] * X[right-left+1];
    }
    

    ULL getWordHash(string s2){
        ULL hash2 = 0;
        for (int i = 0; i < s2.length(); i++) {
            hash2 = hash2 * x + s2[i];
        }
        return hash2;
    }


public:
	
	// dp + map + 字符串hash 
	// 4 ms
    bool wordBreak1(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);

        Hash(s);
        unordered_map<ULL, int> mp;

        for (int i = 0; i < wordDict.size(); i++) {
            ULL hashcode = getWordHash(wordDict[i]);
            mp[hashcode] = 1;
        }
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                ULL code = getHash(s, j, i-1);
                if (dp[j] && mp[code]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    
    //dp + set
    // 24 ms
    bool wordBreak2(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);

        set<string> st;
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
				// 耗时： substr > find 
                if (dp[j] && st.find(s.substr(j,i-j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    // 暴力解法 + 滑动窗口
    //"aaaaaaa", ["aaaa","aaa"] case 不通过 
	bool wordBreak3(string s, vector<string>& wordDict) {
        int start = 0, n = s.size();
        int ans = 0;
        for (int i = 0; i < n && start < n; i++) {
            string substr = s.substr(start, i-start+1);
            // cout <<substr << endl;

            for (int k = 0; k <wordDict.size(); k++) {
                if (wordDict[k] == substr) {
                    // cout << start << " " << i << " " << substr << endl;
                    ans += substr.size();
                    start = i+1;
                    break;
                }
            }
        }
        return ans == n;
    }  
};

int main() {
	string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	
	Solution solu;
	cout << solu.wordBreak1(s, wordDict) << endl;
} 


