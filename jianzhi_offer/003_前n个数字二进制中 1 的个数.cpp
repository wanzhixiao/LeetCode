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
            ans[i] = ans[i-highBits] + 1;   //1就是ans[highBits]
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
	思路：从二进制的最高位开始累加1
		最高为是指离x最近的2的幂指数, 如
		3 = 2 + 1, 3的最近的2的幂指数为2 
		7 = 4 + 3, 7的最近的2的幂指数为4 
	
	1.从1遍历到n
	2.判断i是否为2的幂指数
		i&(i-1) == 0;  highBits = i; 
	bits[i]为 第i个数的2进制中1的	个数
	bits[i] = bit[i-highBits] + 1 //2的幂指数中1的个数为1 
*/

int main(){
	Solution s;
	cout << (4<<1) << endl;		//1100
	vector<int> ans = s.countBits1(5);
	
	//N*2^x = 2*2^3
	//4<<5 , N=4, x=5; 4*2^5 = 4*32 = 128 
	
	
	
	return 0;
} 
