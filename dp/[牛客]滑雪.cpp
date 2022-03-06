#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 105;
int map[MAXN][MAXN];
int dp[MAXN][MAXN];

int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int getlength(int x, int y, int n, int m)
{
    //µÝ¹é±ß½çÌõ¼þ
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return 0;
    }
    
    if (dp[x][y] != 1)
    {
        return dp[x][y];
    }

    int maxlen = 1;
    for (int i = 0; i < 4; i++)
    {
        int dx = x + direction[i][0];
        int dy = y + direction[i][1];
        
        if (map[dx][dy] < map[x][y])
        {
           maxlen = max(maxlen, getlength(dx,dy,n,m)+1); 
        }  
    }
    
    dp[x][y] = maxlen;
    return dp[x][y];
}

int main()
{
    int n = 0, m = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&map[i][j]);
            dp[i][j] = 1;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        	int maxlen = getlength(i,j,n,m);
//			printf("%d ",maxlen);
            ans = max(ans,maxlen);
        }
//        printf("\n");
    }
    printf("%d\n",ans);
    
    return 0;
}
