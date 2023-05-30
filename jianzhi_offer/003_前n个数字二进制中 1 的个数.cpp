#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        ans[0] = 0;
        int highBits = 0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))== 0){
                highBits = i;
            }
            ans[i] = ans[i-highBits] + 1;   //1����ans[highBits]
        }
        return ans;
    }
    
    int lowBit(int x){
    	return x&-x;
	} 
    
    vector<int> countBits1(int n) {
    	vector<int> ans(n+1,0);
        ans[0] = 0;
        for(int i=1; i<=n; i++) {
        	int cnt = 0;
        	int x = i;
        	while(x) {
        		x -= lowBit(x);
        		cnt++;
			}
			cout << cnt << ' '; 
			ans[i] = cnt;
		}
		return ans;
    }
};

/*
	˼·���Ӷ����Ƶ����λ��ʼ�ۼ�1
		���Ϊ��ָ��x�����2����ָ��, ��
		3 = 2 + 1, 3�������2����ָ��Ϊ2 
		7 = 4 + 3, 7�������2����ָ��Ϊ4 
	
	1.��1������n
	2.�ж�i�Ƿ�Ϊ2����ָ��
		i&(i-1) == 0;  highBits = i; 
	bits[i]Ϊ ��i������2������1��	����
	bits[i] = bit[i-highBits] + 1 //2����ָ����1�ĸ���Ϊ1 
*/

int main(){
	Solution s;
	cout << (4<<1) << endl;		//1100
	vector<int> ans = s.countBits1(5);
	
	//N*2^x = 2*2^3
	//4<<5 , N=4, x=5; 4*2^5 = 4*32 = 128 
	
	
	
	return 0;
} 
