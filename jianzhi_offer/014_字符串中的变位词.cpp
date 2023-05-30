#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


/*
问题：判断字符串s2是否包含s1的全排列；
	例如 s1 = "ab" s2 = "eidbaooo" true,
 		s1= "ab" s2 = "eidboaoo" false
 		
	只需要判断s2的连续子串s2[i...j]是否包含s1的全部字符

	思路，维护一个滑动窗口 当s2[right]的字符进入 窗口时，cnt2[s2[right]]++; , cnt2[s2[left]]--;
	当 cnt2 == cnt1时，说明cnt2对应的子串包含了s1,返回true;
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        unordered_map<char,int> need, window;
        int valid = 0, left = 0, right = 0;
        for (int i = 0; i < m; i++) {
        	++need[s1[i]];
		}
		cout << endl;
		
		for(auto &x : need) {
			cout << x.first << " " << x.second << endl;
		}
		
        for (; right < n; right++) {
     
        	if (window[s2[right]] < need[s2[right]]) {
        		cout << "valid=" << valid << endl;
        		valid++;
        		cout << "valid=" << valid << endl;
			}
			cout << "valid=" << valid <<" left="<< left << " right=" << right << " " << s2[right] <<  " need[s2[right]]=" << need[s2[right]] << " window[s2[right]]=" << window[s2[right]] << endl;
			window[s2[right]]++;
			
			while (right - left >= m) {
//				cout << s2[left] << " need.count(s2[left]) = " << need.count(s2[left]) << endl;
				if (need.count(s2[left]) != 0 && (window[s2[left]] <= need[s2[left]])) {
					cout << "left=" << s2[left] << " need.count(s2[left])= "<< need.count(s2[left]) << endl;
					valid--;
				}
				--window[s2[left]];
				left = left + 1;
			}
			
			if(valid == m) {
				return true;
			}
			
		}
		return false;
    }
    
    bool checkInclusion2(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = n; i < m; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
	//https://leetcode.cn/problems/MPnaiL/solution/zi-fu-chuan-zhong-de-bian-wei-ci-by-leet-wbma/
};

int main() {
	string s = "a";
	string t = "a";
	
	Solution solu;
	cout << solu.checkInclusion(s,t) << endl;
	return 0;
}
