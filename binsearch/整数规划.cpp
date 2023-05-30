#include<iostream>
#include<vector> 
using namespace std;

int zeroOnePack(vector<int> &weight,int C) {
	int n = weight.size();
	vector<int> dp(C+1,0);
		
	for (int i = 0; i < n; i++) 
	{
		for (int j=C; j >= weight[i]; j--) 
		{
			dp[j] = max(dp[j],dp[j-weight[i]]+weight[i]);
		}
	}
	return dp[C];
}


int main() {
	vector<int> weight = {2,4,6};
	int C = 9;
	cout << zeroOnePack(weight,C) << endl;
	return 0;
} 

/*
N¼ÒÃÅµê£º
weight = [2,4,6]
value = [2,4,6]
C = 9
C >= max(weight[i],i =[0,...,i]}

2+4+6 / 9 = 2

9
[6,4,2]
3-1 = 2


max sum xi*Wi
	xi = [0, 1]
	sum wi*xi <= C
	
min [x11,x12,x13,...,x1n]  <= 1
	[x21,x22,x3,...,xn]


	[x1,x2,x3,...,xn] * wi
	sum(x1,x2,..,xn) = 1
	sum([x1,x2,x3,...,xn] * wi) <= C
	
*/ 
