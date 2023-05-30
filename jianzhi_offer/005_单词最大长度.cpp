#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*
������󳤶ȣ���һ���������ҳ��������ʣ�����1�е��ַ�û���ڵ���2�г��ֹ���
	�������������ʳ��ȵ����˻� 
˼·1����������ö�����еĵ��ʶԣ��жϵ���1���ַ��Ƿ�����ڵ���2�У����û�г��֣����ǿ��ܵĴ�֮1
	ʱ�临�Ӷ�O(n^2) * O(word_size) 
˼·2��λ���� 
	ʹ��λ����Ԥ����ÿ������, mask[i] = mask[i] | 1<<(word[j]-'a');  a = a | b;  ȡ�����ַ�λ����Ĳ��� 
	https://leetcode.cn/problems/aseY1I/solution/hua-luo-yue-que-bei-li-yong-che-di-de-er-loai/ 
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            string word1 = words[i];
            for(int j=1;j<n;j++){
                string word2 = words[j];
                bool flag = false;
                for(int k=0;k<word1.size();k++){
                    if(word2.find(word1[k]) != string::npos){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    ans = ans > (word1.size()*word2.size()) ? ans : (word1.size() * word2.size());
                }
            }
        }
        return ans;
    }
    
    int maxProduct2(vector<string>& words) {
    	int ans = 0;
    	int n = words.size();
    	if (n <= 1) {
    		return ans;
		}
    	vector<int> mask(n,0);
    	for (int i = 0; i < n; i++){
    		string word = words[i];
    		int len = word.length();
    		for (int j = 0; j < len; j++){
    			//a|=b�ȼ���a=a|b;
    			mask[i] |= 1<<(word[j]-'a');
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if ((mask[i] & mask[j]) == 0) {
					int len = words[i].length() * words[j].length();
					ans = ans > len ? ans : len;
				}
			}
		} 
		return ans; 
	}	
};

int main(){
	vector<string> words = {"abcw","baz","foo","bar","fxyz","abcdef"};
	Solution s;
	cout << s.maxProduct2(words) << endl;
	return 0;
} 
