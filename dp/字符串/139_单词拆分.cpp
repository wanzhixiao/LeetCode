#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

/*
���ʲ��

1. �����ⷨ�� ��������ƥ��

2. dp + hashset

3. dp + �ַ���hash 


dp������
	��wordDict�е�ÿ�����ʴ浽hashset�� 

dp[i]��ʾs[0...i-1]�Ƿ��ܱ��ո��ֳ����ɸ��ֵ��г��ֵĵ���
s[0...i-1] = s[0...j-1] + s[j...i-1];  �ж�s[0...j-1], s[j...i-1]�Ƿ�������ֵ���

dp[0] = true;       //�մ��������ֵ���
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
	
	// dp + map + �ַ���hash 
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
				// ��ʱ�� substr > find 
                if (dp[j] && st.find(s.substr(j,i-j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    // �����ⷨ + ��������
    //"aaaaaaa", ["aaaa","aaa"] case ��ͨ�� 
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


