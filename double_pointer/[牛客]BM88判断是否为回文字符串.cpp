#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param str string字符串 待判断的字符串
     * @return bool布尔型
     */
    bool judge(string str) {
    	int n = str.size();
		if(n<=1) {
			return true;
		}
		
		for(int i = 0; i<n/2;i++){
			if(str[i] != str[n-i-1]){
				return false;
			}
		}
		return true;
    }
    
    bool judge1(string str) {
    	int n = str.size();
		if(n<=1) {
			return true;
		}
		
		int i=0,j=n-1;
		while(i<j){
			if(str[i]!=str[j]){
				return false;
			}
			i++;
			j--;
		} 
		return true;
    }
};

int main(){
	string str;
	cin >> str;
	Solution s;
	
	cout << s.judge1(str) << endl;
	 
	return 0;
} 
