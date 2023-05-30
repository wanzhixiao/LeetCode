#include<string>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;

/*
���ظ��ַ�����Ӵ�
��������+set��
	���ڴ���ĺ��壺�������ظ��ַ����Ӵ�
	��ʱ�ƶ���ָ�룺set�в�����s[right],��s[right]���� 
	��ʱ�ƶ���ָ�� : set�а���s[right]ʱ��
			 ����ans = max(ans,right-left+1) 
			��s[left]��set���Ƴ���ͬʱ��ָ�����ƶ� 
*/ 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, n = s.length();
        int r = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        while (r < n) {
            while (mp.find(s[r]) != mp.end()) {
                mp.erase(s[l]);
                l = l+1;
            }
            ans = max(ans, r-l+1);
            mp[s[r]] = r;
            r++;
        }
        return ans;
    }
};

int main() {
	string s = "abcabcbb";
	Solution solu;
	cout << solu.lengthOfLongestSubstring(s) << endl;
	return 0;
} 
