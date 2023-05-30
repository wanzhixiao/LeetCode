#include<iostream>
#include<vector>
#include<string>
using namespace std;


// bfs 
class Graph {
    vector<vector<pair<int,int>>> g;
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        //建图
        this->n = n;
        g.resize(n);
        for (vector<int> e : edges) {
            g[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dis(this->n, 0x3f3f3f3f);
        dis[node1] = 0;
        queue<int> q;
        q.push(node1);
        int ans = 0x3f3f3f3f;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            // 碰到node2直接返回，bfs第一次遍历到的可能不是权重和最小的最短路径
            // if (x == node2) {
            //     return dis[x];
            // }
            for (pair<int,int> p : g[x]) {
                int y = p.first, c = p.second;
                if (dis[x] + c < dis[y]) {
                    dis[y] = dis[x] + c;
                    q.push(y);
                }
            }
        }
        return dis[node2] == 0x3f3f3f3f ? -1 : dis[node2];
    }
};


// 迪杰斯特拉求单源最短路径 
class Graph2 {
    vector<vector<pair<int,int>>> g;
    int n;
public:
    Graph2(int n, vector<vector<int>>& edges) {
        //建图
        this->n = n;
        g.resize(n);
        for (vector<int> e : edges) {
            g[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> vis(this->n,false);
        vector<int> dis(this->n, 0x3f3f3f3f);
        for (pair<int,int> p : g[node1]) {
            dis[p.first] = p.second;
        }
        vis[node1] = true;
        dis[node1] = 0;

        for (int i = 0; i < this->n - 1; i++) {
            int mind = 0x3f3f3f3f;
            int u = 0;
            for (int j = 0; j < this->n; j++) {
                // 从 V-S中找一个最近的节点
                if (!vis[j]) {
                    if (dis[j] < mind) {
                        mind = dis[j];
                        u = j;
                    }
                }
            }
            //剪枝
            if (u==node2) {
                return dis[u] == 0x3f3f3f3f ? -1 : dis[u];   
            }
            //将u加入到S中
            vis[u] = true;
            //更新以u为中间点的距离
            for (pair<int,int> p1 : g[u]) {
                int v = p1.first, w = p1.second;
                if (!vis[v] && (dis[v] > dis[u] + w)) {
                    dis[v] = dis[u] + w;
                }
            }

        }
        return dis[node2] == 0x3f3f3f3f ? -1 : dis[node2];
    }
};


//弗洛依德算法 
class Graph {
    int g[101][101];
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        //建图
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = 1e8;
            }
            g[i][i] = 0;
        }
        for (vector<int> e : edges) {
            g[e[0]][e[1]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int w = edge[2];
        if (w > g[edge[0]][edge[1]]) return;
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                g[i][j] = min(g[i][j], g[i][edge[0]] + w + g[edge[1]][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return g[node1][node2] == 1e8 ? -1 : g[node1][node2];
    }
};


int main() {
	int a = -15;
	int c = 5;
	string b = to_string(a);
	string d = to_string(c);
	cout << d.size() << endl;
	return 0;
}
