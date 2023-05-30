#include<iostream>
#include<vector>
#define N 6050
using namespace std;
int h[N];
int f[N][2]; 
int n;

void dfs(int u, int fa, vector<vector<int>> &g) {
    f[u][0] = 0; f[u][1] = h[u];
    for (int v : g[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v,u,g);
        f[u][0] += max(f[v][1],f[v][0]);
        f[u][1] += f[v][0];
    }
//    cout << u << " " << f[u][0] << " " << f[u][1] << endl; 
}

int main() {
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        h[i] = a;
    }
    for (int i = 0; i < n-1; i++) {		// 不包括根节点，根节点没有上司 
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        p[a] = 1;
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0){
            root = i;
            break;
        }
    }
    dfs(root,0, g);
    cout << max(f[root][0],f[root][1]) << endl;
}

/*
					5
				  /  \
				 4   3
			    /\  / \
			   6 7  1 2
不选3和4. 最大的happy为5 
节点编号 不选 选 
6 		0 	1
7 		0 	1
4 		2 	1
1 		0 	1
2 		0 	1
3 		2 	1
5 		4 	5
5

*/
