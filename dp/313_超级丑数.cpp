#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		int m = primes.size();
		vector<int> pointer(m,0);			//pointer[i]表示第i个primes的指针 
		vector<long> dp(n+1,0);				//dp[i]表示第i个丑数是多少 
		vector<long> nums(m,1);
		
		for (int i = 1; i <= n; i++) {
			long tmp = INT_MAX;
			for (int j = 0; j < m; j++) {
				cout << " " << nums[j];
				tmp = min(tmp,nums[j]);
			}
			cout << endl;
			dp[i] = tmp;
			for (int j = 0; j < m; j++) {
				if (tmp == nums[j]) {
					++pointer[j]; 
					nums[j] = dp[pointer[j]]*primes[j];
				}
			}
		}
		return dp[n];
    }
    
    //264 丑数 
    int nthUglyNumber(int n) {
        vector<long> dp(n+1,0);
        vector<long> nums(3,1);
        vector<int> pointer(3,0);
        vector<int> primes = {2,3,5};
        for (int i = 1; i <= n; i++) {
            int minVal = INT_MAX;
            for (int j = 0; j < 3; j++) {
                 minVal = minVal < nums[j] ? minVal:nums[j];
            }
            dp[i] = minVal;
            for (int j = 0; j < 3; j++) {
                if (minVal == nums[j]) {
                    ++pointer[j];
                    nums[j] = dp[pointer[j]] * primes[j];
                }
            }
        }
        return dp[n];
    }
};

int main() {
	
	vector<int> vec = {2,7,13,19};
	int n = 12;
	Solution solu;
	cout << solu.nthSuperUglyNumber(n,vec) << endl;
	
	return 0;
} 
