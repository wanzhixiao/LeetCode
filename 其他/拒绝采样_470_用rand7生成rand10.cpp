#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


int rand7() {
	int a = rand() % 7 + 1;
	return a;
}

int rand10() {
	while (true) {
		int a = rand7();
		int b = rand7();
		int c = (a-1)*7 + b;	//[1,42] + [1,7] -> [1,49]
		
		if (c <= 40) {
			return c % 40 + 1;
		}
	}
	return 1;
}


//减少拒绝(浪费)的次数 
int rand100() {
    while (true) {
      	int a = rand7();
        int b = rand7();
        int c = (a-1)*7 + b;	//[1,42] + [1,7] -> [1,49]
        
        if (c <= 40) {
            return c % 10 + 1;
        }
		
		//最后剩下9个数 
        //c > 40
        int d = c - 40;
        b = rand7();
        a = (d-1)*7 + b;
        if (a <= 60) {
            return a % 10 + 1;
        }
		
		//最后剩下3个数 
        //a > 60
        int e = a - 60;     //1,2,3
        b = rand7();
        a = (e-1) * 7 + b;  //[1,21]
        
        //最后剩下1个数 
        if (a <= 20) {
            return a%10 + 1;
        }
    }
    return 1;
}


int main() {
	srand(time(NULL));
	
	cout << rand100() << endl;
	
	return 0;
} 
