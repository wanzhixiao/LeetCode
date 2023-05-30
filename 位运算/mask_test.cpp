#include<iostream>
using namespace std;

int main() {
	int a = 1, b = 2, c = 3;
	int mask = 1<<a;
	cout << mask << endl;
	cout << (1<<b) << endl;
	mask |= (1<<b);					//  1<<2 = 4   2 |= 4 =    010 | 100 = 110
	mask |= (1<<c);
	cout << mask << endl;			//  1 1 1 0;			//从左至右，第1位，第2位，第3位都有1
	
	cout << (mask >> c) << endl; 	//剩下原来的最高位1   0001
	cout << (mask >> b) << endl; 	//剩下 0011 
	cout << (mask >> a) << endl;
	
	int d = 8;
	cout << (d & (-d)) << endl;     // 8 
	
	return 0;
} 
