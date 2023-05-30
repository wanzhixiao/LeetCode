#include<iostream>
#include<vector>
#define N 1502
using namespace std;

int n;
int f[N][2];

int dfs(int u, int fa, vector<vector<int>> &g){
    f[u][0] = 0;
    f[u][1] = 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v,u,g);
        //不选u 
        f[u][0] += f[v][1];
        //选u 
        f[u][1] += min(f[v][1],f[v][0]);
    }
}

int main() {
    int k, u, v;
    cin >> n;
    vector<int> din(n,1);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            din[v] += 1;
        }
    }
    //寻找入度为0的root
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (din[i] == 0) {
            root = i;
            break;
        }
    }
    dfs(root, -1, g);
    cout << min(f[root][0], f[root][1]) << endl;
    return 0;
}
