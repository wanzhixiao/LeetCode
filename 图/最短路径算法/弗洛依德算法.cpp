#include<iostream>
#include<vector>
#include<string.h>
#define N 10
#define INF 65535
using namespace std;

int graph[N][N];

/*
弗洛伊德算法
	求所有点之间的最短距离 
核心思想：
	经由中转点k所能得到的最短距离
	弗洛伊德是一种动态规划算法,u是起点，v是终点，k是中转点 
	for k
		for u
			for v
				dist[u][v] = min(dist[u][v],dist[u][k]+dist[k][v])
	时间复杂度O(n^3) 
问题：
	为什么是最外层为中转点k 
	因为floyd本质目的是对于每个点对i-j的距离可以被其它点优化，而且可以被多个点共同优化，
	如果循环k在内层，那么i,j每次只能得到一个点的优化。
	例如 
	1 -> 3 -> 4 ->2
	\ _ _ _ _ _ /
	点1-2的路径只能通过单一的点，k在最内部： 
	1与2之间的最短路径，要么通过3，要么通过4； 1->3->2, 和1->4->2; 没有考虑到同时使用3，4来优化,即1->3->4->2
参考：https://blog.csdn.net/RunningBeef/article/details/114683747 
*/ 

void floyed(int n) {
	//中间点 
	for (int k = 0; k < n; k++) {
		//起点 
		for (int v0 = 0; v0 < n; v0++) {
			//终点
			for (int v1 = 0; v1 < n; v1++) {
				if (graph[v0][k] + graph[k][v1] < graph[v0][v1]) {
					graph[v0][v1] = graph[v0][k] + graph[k][v1];
				} 
			} 
		} 
	}
}

int main() {
	int ne = 10, nv = 6;
	int edges[][3] = {{0,1,2},{0,2,5},{1,2,1},{1,3,3},{2,3,3},{2,4,4},{2,5,1},{3,4,1},{3,5,4},{4,5,1}};
	
	//二维整型数组直接利用 memset() 函数初始化时，只能初始化为 0 或 -1 ，否则将会被设为随机值
	//手动初始化 
	for (int i = 0; i < nv; i++) {
		for (int j = 0; j < nv; j++) {
			graph[i][j] = INF;
		}
		graph[i][i] = 0;
	}
	//初始化边 
	int start = 1;
	for (int i = 0; i < ne; i++) {
		int v0 = edges[i][0];
		int v1 = edges[i][1];
		int w = edges[i][2];
		graph[v0][v1] = w;
	}

	floyed(nv);
	for (int i = 0; i < nv; i++) {
		for (int j = 0; j < nv; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
