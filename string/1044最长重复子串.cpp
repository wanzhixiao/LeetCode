#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    typedef unsigned long long ULL;
    ULL H[30010];
    ULL X[30010];
    ULL x = 13331;
    
    void hash(string &s) {
        int n = s.length();
        H[0] = s[0];
        X[0] = 1;
        for (int i = 1; i < n; i++) {
            H[i] = H[i-1] * x + s[i];
            X[i] = X[i-1] * x;
        }
    }

    ULL gethash(string &s, int left, int right) {
        if (left == 0) {
            return H[right];
        }
        return H[right] - H[left-1] * X[right-left+1];
    }

    string check(string &s, int len){
        int n = s.length();
        unordered_map<ULL,int> mp;
        string ans = "";
        for (int i = 0; i + len <= n; i++) { //细节4 i+len <= n; 左端点能够取到n-len 
            int j = i+len-1;                //细节5 s[i...i+len-1]
//            cout << i << " " << j << endl;
            ULL code = gethash(s, i, j);
            if (mp[code]) {
                ans = s.substr(i,len);
                break;
            }
            ++mp[code];
        }
        return ans;
    }
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        hash(s);
        string ans = "";
        int left = 0, right = n;
        while (left < right) {				 //细节1 左闭右开区间[left, right) 
            int mid = (left+right+1) >> 1;   //细节2 向上取整
//            cout <<left << " " << right << " " << mid << endl;
            string str = check(s,mid);
            if (str.length() > 0) {
                left = mid;
            } else {
                right = mid - 1;			//细节3,收缩右边界 
            }
            ans = ans.length() > str.length() ? ans : str;
        }
        return ans;
    }
};

int main() {
	string s = "banana";
	Solution solu;
	cout << solu.longestDupSubstring(s) << endl;
	return 0;
} 
