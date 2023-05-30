#include<bits/stdc++.h>
#define N 101
using namespace std;

int f[N];


/*
f[i]表示第i个树的斐波那契值，
f[i] = f[i-1] + f[i-2];
f[0] = 0;
f[1] = 1;
*/
int fibonacii1(int n){
    if(n<=1){
        return n;
    }
    return fibonacii1(n-1)+fibonacii1(n-2);
}

int fibonacii2(int n){
    if(n<=1){
        return n;
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n-1] = fibonacii2(n-1);
    f[n-2] = fibonacii2(n-2);
    f[n] = f[n-1]+f[n-2];
    return f[n];
}

int fibonacii3(int n){
    f[0] = 0;
    f[1] = 1;
    for(int i=2;i<=n;i++){

        f[i] = f[i-1]+f[i-2];
        cout << f[i] << " " << f[i-1] << " " << f[i-2] << endl;
    }
    return f[n];
}

int fibonacii4(int n){
    int a=0,b=1,c=0;
    for(int i=2;i<=n;i++){
        c = a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(){
    int n = 5;
    memset(f,-1,sizeof(f));
    // cout << fibonacii1(n) << endl;
    // cout << fibonacii2(n) << endl;
    cout << fibonacii3(n) << endl;
    // cout << fibonacii4(n) << endl;
    return 0;
}