#include<iostream>
#include<vector> 
using namespace std;


int ans = 0;
void backtracking(vector<vector<char>> &board,int row,int n);
bool isValid(vector<vector<char>> &board,int row,int col,int n);

int solveNQueens(int n)
{
	vector<vector<char>> board(n,vector<char>(n,'.')); 
	backtracking(board,0,n);
	return ans;
}

void backtracking(vector<vector<char>> &board,int row,int n)
{
	if(row==n)
	{
		ans += 1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				putchar(board[i][j]);
				putchar(' ');
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	for(int col=0; col<n; col++)  //横向尝试不同列 
	{
		if(!isValid(board,row,col,n))  
		{
			continue;
		}
		board[row][col] = '#';
		backtracking(board,row+1,n); //纵向搜索下一行 
		board[row][col] = '.';
	}
}

bool isValid(vector<vector<char>> &board,int row,int col,int n)
{
	//左上方
	for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
	{
		if(board[i][j] == '#')
		{
			return false;
		}
	} 
	//正上方 
	for(int i=0;i<row;i++)
	{
		if(board[i][col] == '#')
		{
			return false; 
		}
	}
	//右上方
	for(int i=row-1,j=col+1;i>=0&&j<n; i--,j++)
	{
		if(board[i][j] == '#')
		{
			return false;
		}
	} 
	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	int ans = solveNQueens(n);
	cout << ans << endl;
	
	return 0;	
} 

