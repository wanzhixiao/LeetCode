#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
/*
利用前缀和的思想；
二维子矩阵和S2 =  S - S1

row2 = 4, col2 = 4, row1 = 2, col1 = 2
S2 =  S[row2][col2]-S[row2][col1-1]-S[row1-1][col2]+S[row1-1][col1-1]
 
*/

class NumMatrix {
private:
    int S[210][210];
    int m = 0;
    int n = 0;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(S,0,sizeof(S));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i==0 && j==0) {
                    S[i][j] = matrix[i][j]; 
                } else if (i==0) {
                    S[i][j] = S[i][j-1] + matrix[i][j]; 	//A[0][j], 第一行 
                } else if(j==0) {
                    S[i][j] = S[i-1][j] + matrix[i][j];	//A[i][0], 第一列 
                } else {
                    S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + matrix[i][j]; 
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if ((row1 == 0 && col1==0) || (row2 == 0 && col2 == 0)) {
            return S[row2][col2];
        }
        if (row1 == 0) {
            return S[row2][col2] - S[row2][col1-1];
        }
        if (col1 == 0) {
            return S[row2][col2] - S[row1-1][col2];
        }
        if (row2 == 0) {
            return S[row2][col2] - S[row1][col1-1];
        }
        if (col2 == 0) {
            return S[row2][col2] - S[row1-1][col1];
        }
        int S1 = S[row2][col2] - S[row2][col1-1] - S[row1-1][col2] + S[row1-1][col1-1];
        return S1;
    }
};

int main() {
	
	return 0;
}
