#include<iostream>
#include<vector>
#include<set> 
using namespace std; 

/*
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子字符串是 "abc"，所以其长度为 3

思路1：滑动窗口 + hashset

	 窗口表示什么：无重复字符的子串
	 何时移动右指针：窗口内无重复字符
	 何时移动左指针：窗口内包含重复字符
思路2：滑动窗口 + 数组
	使用数组作为hashset, 当右侧ch[s[right]] >= 1时， 我们右移左指针，left++;
	否则，窗口内不存在重复字符时，++ch[s[right]]
	效率比 st.find(s[right])快很多 

*/

class Solution {
    char ch[128];
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int left = 0, right = 0;
        int n = s.length();
        int ans = 0;
        while (right < n) {
            while (ch[s[right]] >= 1 && left < right) {
                --ch[s[left]];
                ++left;
            }
            ans = max(ans, right-left+1);
            ++ch[s[right]];
            right++;
        }
        return ans;
    }
};

int main() {
	string s = "asdfghjkdert";
	Solution solu;
	cout << solu.lengthOfLongestSubstring(s) << endl;
	
	return 0;
}
