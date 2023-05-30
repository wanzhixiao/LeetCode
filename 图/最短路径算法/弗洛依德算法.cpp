#include<iostream>
#include<vector>
#include<string.h>
#define N 10
#define INF 65535
using namespace std;

int graph[N][N];

/*
���������㷨
	�����е�֮�����̾��� 
����˼�룺
	������ת��k���ܵõ�����̾���
	����������һ�ֶ�̬�滮�㷨,u����㣬v���յ㣬k����ת�� 
	for k
		for u
			for v
				dist[u][v] = min(dist[u][v],dist[u][k]+dist[k][v])
	ʱ�临�Ӷ�O(n^3) 
���⣺
	Ϊʲô�������Ϊ��ת��k 
	��Ϊfloyd����Ŀ���Ƕ���ÿ�����i-j�ľ�����Ա��������Ż������ҿ��Ա�����㹲ͬ�Ż���
	���ѭ��k���ڲ㣬��ôi,jÿ��ֻ�ܵõ�һ������Ż���
	���� 
	1 -> 3 -> 4 ->2
	\ _ _ _ _ _ /
	��1-2��·��ֻ��ͨ����һ�ĵ㣬k�����ڲ��� 
	1��2֮������·����Ҫôͨ��3��Ҫôͨ��4�� 1->3->2, ��1->4->2; û�п��ǵ�ͬʱʹ��3��4���Ż�,��1->3->4->2
�ο���https://blog.csdn.net/RunningBeef/article/details/114683747 
*/ 

void floyed(int n) {
	//�м�� 
	for (int k = 0; k < n; k++) {
		//��� 
		for (int v0 = 0; v0 < n; v0++) {
			//�յ�
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
	
	//��ά��������ֱ������ memset() ������ʼ��ʱ��ֻ�ܳ�ʼ��Ϊ 0 �� -1 �����򽫻ᱻ��Ϊ���ֵ
	//�ֶ���ʼ�� 
	for (int i = 0; i < nv; i++) {
		for (int j = 0; j < nv; j++) {
			graph[i][j] = INF;
		}
		graph[i][i] = 0;
	}
	//��ʼ���� 
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
