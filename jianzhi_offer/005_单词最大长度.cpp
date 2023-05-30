#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*
单词最大长度：从一个数组中找出两个单词，单词1中的字符没有在单词2中出现过，
	求这样两个单词长度的最大乘积 
思路1：暴力法，枚举所有的单词对，判断单词1的字符是否出现在单词2中，如果没有出现，则是可能的答案之1
	时间复杂度O(n^2) * O(word_size) 
思路2：位运算 
	使用位运算预处理每个单词, mask[i] = mask[i] | 1<<(word[j]-'a');  a = a | b;  取两个字符位运算的并集 
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
    			//a|=b等价于a=a|b;
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
