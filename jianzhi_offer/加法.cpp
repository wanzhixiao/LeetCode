#include<iostream>
#include<cmath>
using namespace std;

int add(int a, int b) {
	int c = 0;
	while (b != 0) {	//����λ���ֲ�Ϊ0ʱ 
		c = a ^ b;		//�޽�λ���� 
		b = (unsigned int)(a & b) << 1;  //��λ���� 
		a = c;
		cout << a << " " << b << " " << c << endl;
	}
	return a;
}
int main() {
	int a = -1;
	int b = -1;
	cout << add(a,b) << endl; 
	return 0;
}
