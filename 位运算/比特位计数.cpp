#include<iostream>
#include<vector>
using namespace std;

/*
338： 比特位计数 
输入：n = 2
输出：[0,1,1]
解释：
0 --> 0
1 --> 1
2 --> 10

思路：
枚举几个例子
0 1 2 3 4 5 6 7的二进制中1的个数分别为
0 1 1 2 1 2 2 3
当 nums[i]为偶数 即 nums[i] & 1 == 0
	dp[i] = dp[i>>1] 
当 nums[i]为奇数时，即 nums[i] & 1 == 1
	dp[i] = dp[i>>1] + 1; 
*/

vector<int> countBits(int n) {
	vector<int> dp(n+1,0);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
//		dp[i] = i%2 ? dp[i>>1] + 1 : dp[i>>1];	
		dp[i] = dp[i>>1] + (i&1);
	}
	return dp;
}

vector<int> countBits2(int n) {
	vector<int> dp(n+1,0);
	dp[0] = 0;
	int highbit = 0;
	for (int i = 1; i <= n; i++) {
		if ((i & (i-1)) == 0) {
			highbit = i;
		}
		dp[i] = dp[i-highbit] + 1; 		//+1 就是小于i的最高位的1 
	}
	return  dp;
}

int reverseBits(int num) {
	int res = 0;
	for (int i = 31; i >= 0; i--) {
		res += (num & 1) << i;
		num >>= 1;
	}
	return res;
}

int main() {
	int n = 7;
	vector<int> ans = countBits2(n);
	for (int &x : ans) {
		cout << x << " ";
	} 
	cout << endl;
	
	const int inf = 0x3f3f3f3f;
  	cout << 0x3f3f3f3f << endl;
	return 0;
} 

//https://blog.csdn.net/weixin_46141936/article/details/120899953
