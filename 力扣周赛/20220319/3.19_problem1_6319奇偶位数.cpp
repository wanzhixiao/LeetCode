#include<vector>
#include<iostream>
#include<functional>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        vector<int> stk;
        while (n != 0) {
            int a = n %2;
            stk.push_back(a);
            n = n/2;
       
        }
        for (int i = 0; i < stk.size(); i++) {
            if (i % 2 == 0) {
                if (stk[i] == 1) {
                    even++;
                }
            } else {
                if (stk[i] == 1) {
                    odd++;
                }
            }
        }
        return {even, odd};
    }
};

int main() {
	 // function<返回值类型(参数类型列表)> pfunc = func 
	function<int(int,int)> job = [&](int a, int b) { return a < b;}; 

	cout << job(1,3) << endl;
}
