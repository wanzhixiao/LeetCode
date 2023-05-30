#include<iostream>
#include<cmath> 
using namespace std;
 
int add(int n, int m)
{
	int num = 0;
	for (int i = 1; i <= m; i++)
	{
		if (n == i)
		{ 
			return pow(2, i- 1);
		}
			
	}
	for (int i = 1; i <= m; i++)
	{
		num += add(n - i, m);
	}
	return num;
}
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	printf("%d", add(n, m));
	return 0;
}
