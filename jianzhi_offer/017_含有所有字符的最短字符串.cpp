#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*
	string s = "ADOBECODEBANC";
	string t = "ABC";
	
	string s = "bdab";
	string t = "ab";
	
	"cabwefgewcwaefgcf"
	"cae"
	
˼·��	��������
	�����е�״̬��ʲô��
	�����������ַ�������s����t���Ӵ� 
	
	��ô��ʾ��״̬��
	map[s[i]]   left<=i<=right
	
	ʲôʱ�򴰿���չ��
	s[left...right]������û��ȫ������t�е�ÿ���ַ� 
	
	ʲôʱ�򴰿�������
	s[left...right]����tʱ, ������������ֵ 
	 
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
        unordered_map<char,int> actionMap;
        int minlen = m+1;
        int left = 0, right = 0;
        while (right < m) {
   			++actionMap[s[right]];
        	while(meet(actionMap,t) && left <= right) {
                if (right - left + 1 < minlen) {
        		    ans = s.substr(left,right-left+1);
                    minlen = right - left + 1;
                }
        		--actionMap[s[left++]];
			}
            ++right;
        }
        return ans;
    }
    
    bool meet(unordered_map<char,int> m, string &t) {
    	for (int i = 0; i < t.size(); i++) {
    		if (m.count(t[i])==0 || m[t[i]] <= 0) {
    			return false;
			}
			--m[t[i]];
		}
		return true;
	}
    
    void outputMap(const unordered_map<char,int> &m) {
    	
    	for (auto  it = m.begin(); it != m.end(); ++it) {
 			cout << " " << it->first << ":" << it->second;
		}
		cout <<  endl;
	}

    void reset(string &t, unordered_map<char,int> &m) {
        for (int i = 0; i < t.size(); i++) {
            ++m[t[i]];
        }
    }
    
    
    string minWindow1(string s, string t) {
     	int m = s.length(), n = t.length();
    	unordered_map<char,int> need;
    	unordered_map<char,int> window;
    	int left = 0, right = 0, valid = 0;
    	int start = 0, minlen = INT_MAX;
		
		for (int i = 0; i < n; i++) {
			++need[t[i]];
		}
		
		while (right < m) {
			char ch = s[right];
			cout << "ch = " << ch <<" window[ch]= "<< window[ch] <<" need[ch]= "<<need[ch] << endl;
			if (window[ch] < need[ch]) {
				valid++;
				cout << "valid="<< valid << endl;
			}
			++window[ch];
			
			while (valid == n) {
                cout << left << " == " << right << " == "<< minlen << endl;
				if ((right - left + 1) < minlen) {
					minlen = right - left + 1;
					start = left; 
				}
				if (need.count(s[left]) != 0 && window[s[left]] <= need[s[left]]) {		//������<= 
					--valid;
					cout << "--valid=" << valid << " s[left]=" << s[left] <<  " window[s[left]]=" << window[s[left]] << " need.count(s[left])="
					<< need.count(s[left]) << endl;
				}
				--window[s[left]];
				++left;
			}
			++right;
		}
        cout << start << " " << minlen << " " << s.substr(start,minlen) << endl;
		return minlen == INT_MAX ? "" : s.substr(start,minlen); 
    }
    
};

int main() {
	string s = "ADOBECODEBANC";
	string t = "ABC";
	Solution solu;
	cout << solu.minWindow1(s,t) << endl;
	return 0;
} 
