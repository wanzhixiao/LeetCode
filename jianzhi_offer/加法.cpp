#include<iostream>
#include<cmath>
using namespace std;

int add(int a, int b) {
	int c = 0;
	while (b != 0) {	//当进位部分不为0时 
		c = a ^ b;		//无进位部分 
		b = (unsigned int)(a & b) << 1;  //进位部分 
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
