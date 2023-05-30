#include<iostream>
using namespace std;

int devide1(int a, int b){
	if (a==INT_MIN && b==-1){
		return INT_MIN;
	}
	int sign = (a>0)^(b>0)?-1:1;
	int ans = 0;
	a = a>0 ? -a : a;
	b = b>0 ? -b : b;
	 
	while(a<=b){
		a = a-b;
		ans++;
	}
	/*
	-22 -3
	-19 -3
	-16 -3
	-13 -3
	-10 -3
	-7 -3
	-4 -3
	*/
	return sign * ans; 
} 

int devide2(int a, int b){
	if (a==INT_MIN && b==-1){
		return INT_MAX;
	}
	int sign = (a>0)^(b>0)?-1:1;
	int ans = 0;
	a = a>0 ? -a : a;
	b = b>0 ? -b : b;
	while(a<=b){
		int value = b;
		int k = 1;
		while(value >= 0x0000000 && a <= value+value){
			value = value + value;    //value = value * 2 
			if(k > INT_MAX/2){
				return INT_MIN;
			}
			k = k + k;
		}
		a -= value;
		ans += k;
	}
	return sign==1 ? ans : -ans; 
} 

int main(){
	int a = 22, b = 3;
	cout << devide2(a,b) << endl;
	return 0;
} 

/*
��ʹ��/������������
���� a = 22, b = 3, ��� 7 
˼·1��
	ʹ�ü��������������һ�����˶��ٴ� 
	22-3=18
	18-3=15
	15-3=12
	... 
	
˼·2��
	ÿ�ζ��ȥ����3,
	22,3						
	22 - (3+3) = 16 							
	22 - (6+6) = 10 				
	22 - (12+12)<0				
	
	a = 10
	10 - 3 = 7					k=1
	7 - 3*2 = 1					k = 2
	
	a - b * 2^k <= 0 ;  k = log2(a/b)
*/
