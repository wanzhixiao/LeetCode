#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


/*
���⣺�ж��ַ���s2�Ƿ����s1��ȫ���У�
	���� s1 = "ab" s2 = "eidbaooo" true,
 		s1= "ab" s2 = "eidboaoo" false
 		
	ֻ��Ҫ�ж�s2�������Ӵ�s2[i...j]�Ƿ����s1��ȫ���ַ�

	˼·��ά��һ���������� ��s2[right]���ַ����� ����ʱ��cnt2[s2[right]]++; , cnt2[s2[left]]--;
	�� cnt2 == cnt1ʱ��˵��cnt2��Ӧ���Ӵ�������s1,����true;
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
