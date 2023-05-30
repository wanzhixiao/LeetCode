#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		int m = primes.size();
        vector<int> nums(m,1);
        vector<int> dp(n+1,0);
        vector<int> indx(m,0);

        for (int i = 1; i <= n; i++) {
            int minval = INT_MAX;

            for (int j = 0; j < m; j++) {
                minval = minval < nums[j] ? minval : nums[j];
            }
            
            dp[i] = minval;
            
            for (int j = 0; j < m; j++) {
            	if (minval == nums[j]) {
            		++indx[j];
            		cout << "indx[j] = " << indx[j] << " dp[indx[j]] = " << dp[indx[j]] << endl;
            		nums[j] = dp[indx[j]] * primes[j];
				}
			}
			
			cout << "i=" << i << " dp[i]=" << dp[i] << endl; 
        }
		
		return dp[n];
    }
}; 

int main() {
	Solution solu;
	int n = 12;
	vector<int> primes = {2,7,13,19};
	cout << solu.nthSuperUglyNumber(n, primes) << endl;
	return 0;
} 

/*
ÊäÈë£ºn = 12, primes = [2,7,13,19]
Êä³ö£º32
[1,2,4,7,8,13,14,16,19,26,28,32]
*/
