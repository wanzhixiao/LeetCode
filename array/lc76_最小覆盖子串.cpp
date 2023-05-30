#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


/*
��С�����Ӵ�
��Ŀ�������ַ��� s���ַ���t, �ҳ�s�а���t����̵��Ӵ�
���룺s = "ADOBECODEBANC", t = "ABC"
�����"BANC"
���ͣ���С�����Ӵ� "BANC" ���������ַ��� t �� 'A'��'B' �� 'C'��

˼·����������
	���ڴ���ʲô�� s������������������t�������ַ����Ӵ�
	��ʱ�ƶ��ұ߽磿 ��������������s[left...right]���Ӵ��в�����t��ȫ���ַ�,�ұ߽���ַ�����+1 
	��ʱ�ƶ���߽磿����������ʱ���������ڣ� ��߽���ַ�����-1 
	
	��right���ұ����Ĺ����У�������ظ����ַ��������Ҫ����һ��map����¼����������ÿ���ַ����ֵĴ���
	��Σ���Ҫ�жϴ����ڸ����ַ����������Ƿ��������t�и����ַ������� 
	
	������߽�ʱ����Ҫһֱ�ж��Ƿ�����s[left...right]������t�е�ȫ���ַ���
	Ҫ�����������������̵�s[left...right] 
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
            //���崰��������������s���Ӵ�
            while (valid == n) {
                if (i-j+1 < minlen) {
                    minlen = i-j+1;
                    ans = s.substr(j,i-j+1);
                }
                --window[s[j]];
                //������������ַ���t�ַ�������Ҫ���ַ�, ���Ҹ��ַ������������t������
                if (need.find(s[j]) != need.end() && window[s[j]] < need[s[j]]) {
                    --valid;
                }
                ++j;    //������ര��
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
