#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int height[N];
int dp1[N];
int dp2[N];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
	{
        scanf("%d",&height[i]);
        dp1[i] = 1;
        dp2[i] = 1;
    }
    

    //�����м������У� �������������еĸ߶ȣ���¼���һ���ĸ߶ȣ��ٿ�ʼ���Ҳ�����½������еĸ߶�
    for (int i = 1;i < n; i++)
	{
        for (int j=0;j<i;j++)
		{
            if(height[j] < height[i])
			{
                if(dp1[i] < dp1[j]+1)
				{
                    dp1[i] = dp1[j]+1;
                }
            }
        }
    }
    for (int j = n-2; j >= 0; j--)
	{
        for (int k = n-1; k > j; k--)
		{
            if (height[j] > height[k])
			{
                if (dp2[j] < dp2[k]+1)
				{
                    dp2[j] = dp2[k]+1;
                }
            }
        }
    }
 	
 	int ans = 1;
 	
 	for (int i = 0; i < n; i++)
 	{

 		ans = max(ans,dp1[i]+dp2[i]); 
// 		cout << dp1[i] <<" "<< dp2[i] << " " << ans << endl;
	}
 	
    cout << n-ans+1 << endl;
    
    return 0;
}

/*
4
173 132 142 161
out : 1
dp1[i] dp2[i] ans
1 2 3
1 1 3
2 1 3
3 1 4
1
*/
