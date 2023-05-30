#include<iostream>
#include<vector>
#define N 1502
using namespace std;

int n;
int f[N][2];
int happy[N];
int d[N];

int dfs(int u, int fa, vector<vector<int>> &g){
    f[u][0] = 0;
    f[u][1] = happy[u];
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v,u,g);
        //不选u 
        f[u][0] += max(f[v][1],f[v][0]);
        //选u 
        f[u][1] += f[v][0];
    }
}

int main() {
    int k, u, v;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> v;
        happy[i] = v;
    }
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        d[u-1] = 1;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    //寻找入度为0的root
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) {
            root = i;
            break;
        }
    }
    dfs(root, 0, g);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}
