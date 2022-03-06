#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * 
     * @param str string�ַ��� ���жϵ��ַ���
     * @return bool������
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
