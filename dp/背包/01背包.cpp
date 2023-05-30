#include<iostream>
#include<vector> 
#include<string.h>
using namespace std;


//01背包  dfs写法 
int dfs(vector<int> &weight, vector<int> &values, int i, int c) {
	// 没有物品 
	if (i < 0) {
		return 0;
	}
	// 背包容量小于物品容量
	if (c < weight[i]) {
		return dfs(weight, values, i-1, c);
	}
	
	//不选和选 
	int res = max(dfs(weight, values, i-1, c), dfs(weight, values, i-1, c-weight[i]) + values[i]);
	return res; 
} 

//01背包  dfs+记忆化搜索 
const int C = 10000;
int memo[C];
int dfs2(vector<int> &weight, vector<int> &values, int i, int c) {
	// 没有物品 
	if (i < 0) {
		return 0;
	}
	if (memo[c] != -1) {
		return memo[c];
	}
	// 背包容量小于物品容量
	if (c < weight[i]) {
		return dfs(weight, values, i-1, c);
	}
	
	//不选和选 
	int res = max(dfs(weight, values, i-1, c), dfs(weight, values, i-1, c-weight[i]) + values[i]);
	memo[c] = res;
	return res; 
} 

int main() {
	memset(memo,-1,sizeof(memo));
	return 0;
}
