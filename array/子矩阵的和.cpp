#include<iostream>
#include<vector>
#include<string.h>
#define N 101
using namespace std;

int A[N][N];
int S[N][N];

int main() {
	int n = 4;
	memset(A,0,sizeof(A));
	memset(S,0,sizeof(S))	;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i % 2 == 0) {
				A[i][j] = j+1;
			} else {
				A[i][j] =  j+5;
			}

			cout << A[i][j] << " ";
		}
		cout << endl; 
	}
	
	cout << "---sum---" << endl;
	//S[i][j] = S[i-1][j]+S[i][j-1]-S[i-1][j-1]+F[i][j] 
	//S[0][j] = S[0][j-1]+A[0][j]
	//S[i][0] = S[i-1][0]+A[i][0]
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i==0 && j==0) {
				S[i][j] = A[i][j]; 
			} else if (i==0) {
				S[i][j] = S[i][j-1] + A[i][j]; 	//A[0][j], 第一行 
			} else if(j==0) {
				S[i][j] = S[i-1][j] + A[i][j];	//A[i][0], 第一列 
			} else {
				S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j]; 
			}
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "---sub matrix sum---" << endl;
	//S1 = S[x2][y2] - S[x2][y1] - S[x1][y2] + S[x1][y1]
	
	int x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	int S1 = S[x2-1][y2-1] - S[x2-1][y1-1] - S[x1-1][y2-1] + S[x1-1][y1-1];
	cout << S1 << endl; 
	
	return 0;
} 

//https://矩阵乘法learn.microsoft.com/zh-cn/previous-versions/visualstudio/visual-studio-2012/hh873134%28v=vs.110%29
