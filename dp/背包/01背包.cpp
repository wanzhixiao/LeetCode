#include<iostream>
#include<vector> 
#include<string.h>
using namespace std;


//01����  dfsд�� 
int dfs(vector<int> &weight, vector<int> &values, int i, int c) {
	// û����Ʒ 
	if (i < 0) {
		return 0;
	}
	// ��������С����Ʒ����
	if (c < weight[i]) {
		return dfs(weight, values, i-1, c);
	}
	
	//��ѡ��ѡ 
	int res = max(dfs(weight, values, i-1, c), dfs(weight, values, i-1, c-weight[i]) + values[i]);
	return res; 
} 

//01����  dfs+���仯���� 
const int C = 10000;
int memo[C];
int dfs2(vector<int> &weight, vector<int> &values, int i, int c) {
	// û����Ʒ 
	if (i < 0) {
		return 0;
	}
	if (memo[c] != -1) {
		return memo[c];
	}
	// ��������С����Ʒ����
	if (c < weight[i]) {
		return dfs(weight, values, i-1, c);
	}
	
	//��ѡ��ѡ 
	int res = max(dfs(weight, values, i-1, c), dfs(weight, values, i-1, c-weight[i]) + values[i]);
	memo[c] = res;
	return res; 
} 

int main() {
	memset(memo,-1,sizeof(memo));
	return 0;
}
