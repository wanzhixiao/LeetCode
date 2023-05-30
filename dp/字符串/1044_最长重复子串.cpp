#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*
思路1：暴力法+哈希set : 超时 
方法2: 字符串哈希
https://leetcode.cn/problems/longest-duplicate-substring/solution/tong-ge-lai-shua-ti-la-er-fen-cha-zhao-z-gc3d/
https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247489813&idx=1&sn=7f3bc18ca390d85b17655f7164d8e660&chksm=fd9cb20acaeb3b1cc78abf05d6fea6d093098998ce877f799ac478247604bd267fbee6fcd989&token=1342991619&lang=zh_CN#rd 
*/

class Solution {
private:
    typedef unsigned long long ULL;
    vector<ULL> h, x;
    const int X = 13331;
    void hash(string &s) {
        int n = s.size();
        h.resize(n+1);
        x.resize(n+1);
        h[0] = s[0];
        x[0] = 1;
        for (int i = 1; i <= n; i++) {
            h[i] = h[i-1]*X +s[i];
            x[i] = x[i-1]*X;
        }
    }
    ULL getHash(int left,int right) {
        return left ? h[right] - h[left-1]*x[right-left+1] : h[right];
    }

public:
	//暴力法 19/67 
	string longestDupSubstring1(string s) {
		int n = s.length();
		unordered_set<string> st;
		int start = 0, maxlen = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				string substr = s.substr(i,j-i+1);
				if (st.find(substr) != st.end()) {
					if (j-i+1 > maxlen) {
						maxlen = j-i+1;
						start = i;
					}		
				}
				st.insert(substr);
			}
		}
		cout << start << endl;
		return s.substr(start,maxlen);
    }
    
    //字符串哈希 26/67 
    string longestDupSubstring2(string s) {
		int n = s.length();
		unordered_map<ULL,int> mp;
        hash(s);
		int start = 0, maxlen = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
                //substr太耗时
				// string substr = s.substr(i,j-i+1);
                ULL hashcode = getHash(i,j);
                if (mp[hashcode] >= 1 && (j-i+1) > maxlen) {
                    maxlen = j-i+1;
                    start = i;
                }
                ++mp[hashcode];
			}
		}
		return s.substr(start,maxlen);
    }
    
     string longestDupSubstring3(string s) {
		int n = s.length();
		unordered_map<ULL,int> mp;
        hash(s);
		string ans = ""; 
		int left = 0, right = n;
		
		while(left<right)
        {
            int mid=(left+right+1)>>1;
            cout <<mid<<endl;
            string t=check(s,mid);
            
            if(t.size()!=0){
            	left = mid;
            	ans = t;
			} else {
            	right = mid-1;
			}
        }
		return ans;
    }
    
    string check(string &s, int len) {
    	int n = s.length();
    	unordered_set<ULL> st;
    	string ans = ""; 
		for (int i = 0; i + len <= n; i++) {
			int j = i + len - 1;
			ULL code = getHash(i,j);
			if (st.count(code)) {		//由于set仅包含唯一元素，set.count(x)返回1或者0
				//为什么是找到重复的就返回, 因为只需要在s[0...n-1]中找到一个长度为len的重复子串 
				ans = s.substr(i,len); 
				break;
			} 
			st.insert(code);
		} 
		return ans;
	}
};

int main() {
	string s = "banana";
	Solution solu;
	cout << solu.longestDupSubstring3(s) << endl; 
	return 0;
} 
