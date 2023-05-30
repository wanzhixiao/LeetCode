#include<iostream>
using namespace std;

typedef char CH;

int main() {

	CH ch = 'a';
	printf("\n%d\n",ch);
	
	//double类型的指针变量定义
//	int aa(5);
//	double *pd=aa;  convert int to double *

//	double dd(2.5),*pd=dd;  //convert double to double *
	double dd(2.5),*pd=&dd;	 
	
	int a=1,b=2,*p[2];
	p[0] = &a, p[1] = &b;
	
	cout << p[0] <<" " << p[1] << endl;
	cout << *p[0] <<" " << *p[1] << endl;
	
	int *q = &a;
	cout <<q<<" "<<&a<< endl; //0x6ffdec 0x6ffdec
	
	return 0;
} 

/*
<<插入运算符
>>提取运算符 
*/
