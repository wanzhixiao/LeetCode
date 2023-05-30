

/* 
根据题目的意思， 读懂题意： 
当 n=2 时，字符串需要由2个元音字符拼接而成，
且满足字典序，可以在 n=1 的基础之上，给每个字符串前面加上新的元音，
字母a后面可以跟a、e、i、o、u，字母e后面可跟e、i、o、u，字母i可跟i、o、u，字母o可跟o、u，
字母u只能跟u，最后形成 ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]

/*
i < j s[i] <= s[j]
如何划分子问题：指定一个数据排列的顺序，是的后面的数据不会影响到前面结果的统计

//一共有i个字符，字符串的第一个字符是哪个字符
j = 0, 表示第一个字符为a, j = 1表示第一个字符为e, j = 2表示第一个字符为i， 以此类推
dp[i][j] 


初始化 dp[1][i] = 1  //['a','e','i','o','u']表示字符串字符数为1时元音字符串数量

*/

#include<iostream>
#include<vector>
using namespace std;

int countPrim(int n) {
	//dp[i][j] 表示第i个字符元音字符串数量 ， j = 0, 表示第i个字符是a， j=1,表示 第i个字符是e,..., j=4表示第i个字符是u 
	vector<vector<int>> dp(n+1,vector<int>(5,0));
	for (int i = 0; i < 5; i++) {
		dp[1][i] = 1;				//只有有个字符的情况， 以字符结尾的字符数都为1 ['a','e','i','o','u'] 
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = j; k < 5; k++) {		//元音 i  < 元音 j ;   
				//减少一个字符数，第k(k>=j)的元音字符创数量
				//i = 1, ['a','e','i','o','u'];    
				//以j=0,即'a'打头为例，当 i = 2时， 'aa', 'ae','ai','ao','au' ；  [i-1 = 1][a后面一个字符所组成的元音字符串的数量 
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	int ans = 0;
	for (int i=0; i < 5; i++) {
		ans += dp[n][i];
	}
	return ans;
}

int main() {
	int n = 4;
	cout << countPrim(n) << endl;
	return 0; 
} 
 
