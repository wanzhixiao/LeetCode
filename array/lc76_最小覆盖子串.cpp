#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


/*
最小覆盖子串
题目：给定字符串 s和字符串t, 找出s中包含t的最短的子串
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。

思路：滑动窗口
	窗口代表什么？ s中满足条件，即包含t中所有字符的子串
	何时移动右边界？ 不满足条件，即s[left...right]的子串中不包含t的全部字符,右边界的字符数量+1 
	何时移动左边界？当满足条件时，收缩窗口， 左边界的字符数量-1 
	
	在right往右遍历的过程中，会出现重复的字符，因此需要设置一个map来记录遍历过程中每个字符出现的次数
	其次，需要判断窗口内各个字符的数量，是否满足大于t中各个字符的数量 
	
	收缩左边界时，需要一直判断是否满足s[left...right]包含了t中的全部字符；
	要求的是满足条件的最短的s[left...right] 
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        string ans = "";
        if (m < n) {
            return ans;
        }
        unordered_map<char,int> window;
        unordered_map<char,int> need;
        int valid = 0;
        for (int i = 0; i < n; i++) {
            ++need[t[i]];
        }
        int minlen = 100001, j = 0;
        for (int i = 0; i < m; i++) {
            if (window[s[i]] < need[s[i]]) {
                ++valid;
            }
            ++window[s[i]];
            //定义窗口是满足条件的s的子串
            while (valid == n) {
                if (i-j+1 < minlen) {
                    minlen = i-j+1;
                    ans = s.substr(j,i-j+1);
                }
                --window[s[j]];
                //如果窗口左侧的字符是t字符串所需要的字符, 并且该字符不能满足组成t的需求
                if (need.find(s[j]) != need.end() && window[s[j]] < need[s[j]]) {
                    --valid;
                }
                ++j;    //收缩左侧窗口
            }
        }
        return ans;
    }
};

int main() {
	string s = "ADOBECODEBANC";
	string t = "ABC";
	Solution solu;
	cout << solu.minWindow(s,t) << endl; 
	return 0;
} 
