#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    double myPow(double x, int n) {
		int power = n;
		if (x == 0) {
			return x;
		}
		if (n == 0) {
			return 1;
		}
		if (n < 0) {
			power *= -1;
			x = 1/x;
		}
		double weight = x;
		double ans = 1;
		while (power != 0) {
			if ((power & 1) == 1) {
				ans *= weight;
			}
			weight *= weight;
			power /= 2;
		}
		return ans; 
    }
};

int main() {
	int x = 3, n = 2;
	Solution solu;
	cout << solu.myPow(x,n) << endl;
	return 0;
}
