#include<string>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;

/*
无重复字符的最长子串
滑动窗口+set：
	窗口代表的含义：不包含重复字符的子串
	何时移动右指针：set中不包含s[right],将s[right]加入 
	何时移动左指针 : set中包含s[right]时，
			 更新ans = max(ans,right-left+1) 
			将s[left]从set中移除，同时左指针右移动 
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
