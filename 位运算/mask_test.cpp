#include<iostream>
using namespace std;

int main() {
	int a = 1, b = 2, c = 3;
	int mask = 1<<a;
	cout << mask << endl;
	cout << (1<<b) << endl;
	mask |= (1<<b);					//  1<<2 = 4   2 |= 4 =    010 | 100 = 110
	mask |= (1<<c);
	cout << mask << endl;			//  1 1 1 0;			//�������ң���1λ����2λ����3λ����1
	
	cout << (mask >> c) << endl; 	//ʣ��ԭ�������λ1   0001
	cout << (mask >> b) << endl; 	//ʣ�� 0011 
	cout << (mask >> a) << endl;
	
	int d = 8;
	cout << (d & (-d)) << endl;     // 8 
	
	return 0;
} 
