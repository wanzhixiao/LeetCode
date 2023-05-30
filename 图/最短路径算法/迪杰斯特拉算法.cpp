#include<iostream>
#include<vector>
#include<string.h>
#define N 10
#define INF 65535
using namespace std;

int graph[N][N];
int dist[N];
int parent[N];

// 迪杰斯特拉算法 
/*
找出源点到其他点的最短路径
核心思想：
	节点集合V, 已经被访问（找到最短路径）的集合S，和未被访问的集合W
	1.每次从W中找到一个距离S最近的点v1 (visited[v1] = false && dist[v1] < INF),  
	2.将v1 加入到集合S中，即visited[v1] = true
	3. 更新以v1为中转点， start -> ... -> v1 -> w w∈W的距离
		if (!visited[w] && (graph[v1][w] + dist[v1] < dist[w]) dist[w] = dist[v1] + graph[v1][w] 
	4. 循环n-1次，直到S中包含了所有节点，即W集合变为空集 
	
体现的是贪心思想： 每次从 W集合中找到一个离S最近的点w
	时间复杂度O(n^2)  
*/ 

int *dijkstra(int v0, int n) {
	//是否被访问数组
	bool visited[N] = {false}; 
	//距离数组
	//初始被访问节点 
	dist[v0] = 0;
	visited[v0] = true;
	int v1 = v0;
	parent[v0] = -1;
	//遍历其余n-1个点 
	for (int i = 1; i < n; i++) {
		int mind = INF;
		//找距离集合S（已经被访问） 最近的一个未被访问的点 
		for (int j = 0; j < n; j++) {
			// 核心过程--选点, 如果j在{V}-{S}中 
			if (!visited[j]) { 
				if (dist[j] < mind) {
					mind = dist[j];
					v1 = j;
				}
			}
		}
		//将v1点加入到被访问的集合S中 
		visited[v1] = true;
		// 更新以v1为中转点的节点的距离 
		for (int i = 0; i < n; i++) {
			if (!visited[i] && (dist[i] > dist[v1] + graph[v1][i])) {
				dist[i] = dist[v1] + graph[v1][i];
				parent[i] = v1;
			}
		} 
	}
	return dist; 
}

int main() {
	int ne = 10, nv = 6;
	int edges[][3] = {{0,1,2},{0,2,5},{1,2,1},{1,3,3},{2,3,3},{2,4,4},{2,5,1},{3,4,1},{3,5,4},{4,5,1}};
	
	//二维整型数组直接利用 memset() 函数初始化时，只能初始化为 0 或 -1 ，否则将会被设为随机值
	//手动初始化 
	for (int i = 0; i < nv; i++) {
		dist[i] = INF;
		for (int j = 0; j < nv; j++) {
			graph[i][j] = INF;
		}
	}
	//初始化边 
	int start = 0;
	for (int i = 0; i < ne; i++) {
		int v0 = edges[i][0];
		int v1 = edges[i][1];
		int w = edges[i][2];
		graph[v0][v1] = w;
		if (v0 == start) {
			dist[v1] = w;
			parent[v1] = v0;
		}
	}

	int *dist = dijkstra(start,nv);
	for (int i = 0; i < nv; i++) {
		cout << "start = "<<start << " end =" << i << " dist = "<< dist[i] << " parent = " << parent[i] << endl;
	} 
	return 0;
} 

/*
1取最后一个字节 2->16->10
00000001 -> 0x01010101 -> 16843009
0
00000000 -> 00000000
-1
11111111 ->  
参考：https://baike.baidu.com/item/%E8%BF%AA%E5%85%8B%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95/23665989 
*/
