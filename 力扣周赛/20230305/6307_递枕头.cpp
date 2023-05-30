#include<iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        
        int ans = 1;
        int direction = 1;
        for (int i = 1; i <= time; i++) {
            if (direction == 1) {
                ans += 1;
            } else if (direction == 2) {
                ans -= 1;
            }
            if (ans == n) {
                direction = 2;          //向后
            }
            if (ans == 1) {
                direction = 1;          //向前
            }
        }
        return ans;
    }
};

int main() {
	int n = 4, time = 5;
	Solution solu;
	cout << solu.passThePillow(n, time) << endl;
	return 0;
}
