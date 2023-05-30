#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef vector<vector<int>> VVI; 
typedef vector<int> VI;
#define rep(i,n) for(int i = 0, i < n; i++)

VI bfs(VVI &edges,int n, int org, int dst) {
	//建图 
	VVI g(n);
	for (VI e : edges) {
		int start = e[0], end = e[1];
		g[start].push_back(end);
		g[end].push_back(start); 
	}
	//初始化距离和父节点数组 
	VI dis(n,-1);
	VI fa(n,-1);
	//初始化队列 
	queue<int> q;
	q.push(org);
	dis[org] = 0; 
	fa[org] = -1;
	//bfs求解最短路径 
	while (!q.empty()) {
		int x = q.front();
		//找到目标点 
		if (x == dst) {
			break;
		} 
		q.pop();
		for (int y : g[x]) {
			//如果y没有被访问过 
			if (dis[y] < 0) {
				fa[y] = x;
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
		if (dis[dst] != -1) {
			break;
		}
	}
	cout << dis[dst] << endl;
	VI path;
	int x = dst;
	while(x != -1) {
		path.push_back(x);
		x = fa[x];
	}
	reverse(path.begin(),path.end());
	return path;
}

int main() {
	VVI edges = {{0,1},{0,2},{0,3},{1,3},{1,5},{2,3},{3,4},{5,4}};
	int n = 6;
	VI path = bfs(edges,n,2,5);
	for (int i = 0, n = path.size(); i < n; i++) {
		cout << path[i] << (i==n-1 ? "" : " -> ");
	}
	cout << endl;
}


/*

   1 -5
 /  \  \
0-  3 -4
 \2/ 

*/ 
