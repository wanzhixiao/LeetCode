#include<iostream>
#include<vector>
#include<string.h>
#define N 10
#define INF 65535
using namespace std;

int graph[N][N];
int dist[N];
int parent[N];

// �Ͻ�˹�����㷨 
/*
�ҳ�Դ�㵽����������·��
����˼�룺
	�ڵ㼯��V, �Ѿ������ʣ��ҵ����·�����ļ���S����δ�����ʵļ���W
	1.ÿ�δ�W���ҵ�һ������S����ĵ�v1 (visited[v1] = false && dist[v1] < INF),  
	2.��v1 ���뵽����S�У���visited[v1] = true
	3. ������v1Ϊ��ת�㣬 start -> ... -> v1 -> w w��W�ľ���
		if (!visited[w] && (graph[v1][w] + dist[v1] < dist[w]) dist[w] = dist[v1] + graph[v1][w] 
	4. ѭ��n-1�Σ�ֱ��S�а��������нڵ㣬��W���ϱ�Ϊ�ռ� 
	
���ֵ���̰��˼�룺 ÿ�δ� W�������ҵ�һ����S����ĵ�w
	ʱ�临�Ӷ�O(n^2)  
*/ 

int *dijkstra(int v0, int n) {
	//�Ƿ񱻷�������
	bool visited[N] = {false}; 
	//��������
	//��ʼ�����ʽڵ� 
	dist[v0] = 0;
	visited[v0] = true;
	int v1 = v0;
	parent[v0] = -1;
	//��������n-1���� 
	for (int i = 1; i < n; i++) {
		int mind = INF;
		//�Ҿ��뼯��S���Ѿ������ʣ� �����һ��δ�����ʵĵ� 
		for (int j = 0; j < n; j++) {
			// ���Ĺ���--ѡ��, ���j��{V}-{S}�� 
			if (!visited[j]) { 
				if (dist[j] < mind) {
					mind = dist[j];
					v1 = j;
				}
			}
		}
		//��v1����뵽�����ʵļ���S�� 
		visited[v1] = true;
		// ������v1Ϊ��ת��Ľڵ�ľ��� 
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
	
	//��ά��������ֱ������ memset() ������ʼ��ʱ��ֻ�ܳ�ʼ��Ϊ 0 �� -1 �����򽫻ᱻ��Ϊ���ֵ
	//�ֶ���ʼ�� 
	for (int i = 0; i < nv; i++) {
		dist[i] = INF;
		for (int j = 0; j < nv; j++) {
			graph[i][j] = INF;
		}
	}
	//��ʼ���� 
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
1ȡ���һ���ֽ� 2->16->10
00000001 -> 0x01010101 -> 16843009
0
00000000 -> 00000000
-1
11111111 ->  
�ο���https://baike.baidu.com/item/%E8%BF%AA%E5%85%8B%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95/23665989 
*/
