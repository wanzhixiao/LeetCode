#include<iostream>
#include<vector>
#include<set> 
using namespace std; 

/*
����: s = "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�������ַ����� "abc"�������䳤��Ϊ 3

˼·1���������� + hashset

	 ���ڱ�ʾʲô�����ظ��ַ����Ӵ�
	 ��ʱ�ƶ���ָ�룺���������ظ��ַ�
	 ��ʱ�ƶ���ָ�룺�����ڰ����ظ��ַ�
˼·2���������� + ����
	ʹ��������Ϊhashset, ���Ҳ�ch[s[right]] >= 1ʱ�� ����������ָ�룬left++;
	���򣬴����ڲ������ظ��ַ�ʱ��++ch[s[right]]
	Ч�ʱ� st.find(s[right])��ܶ� 

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
