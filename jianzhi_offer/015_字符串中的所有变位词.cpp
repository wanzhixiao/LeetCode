#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<int> ans;
        if (m < n) {
            return ans;
        }
        vector<int> cnt1(26,0),cnt2(26,0);
        for (int i = 0; i < n; i++) {
            ++cnt1[s[i]-'a'];
            ++cnt2[p[i]-'a'];
        }
        if (cnt1 == cnt2) {
            ans.push_back(0); 
        }
        for (int i = 0; i < m-n; i++) {
            --cnt1[s[i]-'a'];
            ++cnt1[s[i+n]-'a'];
        if (cnt1 == cnt2) {
                ans.push_back({i+1});
            }
        }
        return ans;
    }
};

int main() {
	string s = "cbaebabacd", p = "abc";
	Solution solu;
	vector<int> ans = solu.findAnagrams(s,p);
	for (int &x : ans) {
		cout << x << " "; 
	}
	cout << endl;
	return 0;
} 
