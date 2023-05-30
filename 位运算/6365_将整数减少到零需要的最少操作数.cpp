#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

class Solution {
private:
	int res = INT_MAX;
public:
    int minOperations(int n) {
        
        backtrack(n,0,n);
        
        return res;
    }
    

    int backtrack(int n, int cnt, int cur) {
		
		if (cur > n) {
			return cnt;
		}
		
		if (cur == 0) {
			return cnt;
		}
		
		cout << cnt << " " << cur << endl;
		
		int ans = 0;
		for (int i = 0; i < sqrt(n)+1; i++) {
//			if (pow(2,i) > cur) {
//				break;
//			}
			ans += backtrack(n, cnt + 1, cur + pow(2,i));
			ans += backtrack(n, cnt + 1, cur - pow(2,i)); 
		}
		cout << ans << " " << res << endl;
		res = min(ans, res);
		return ans;
	} 
	
	int minOperations2(int n) {
        int  ans = dfs(n);
        return ans;
    }
    
    int dfs(int x) {

        if ((x & (x-1)) == 0) {  //ÊÇ2µÄÃÝ´Î
            return 1;
        }
        int lb = x & -x;
        cout << lb << endl;
        return 1 + min(dfs(x+lb),dfs(x-lb));
    }
};

int main() {
	int n = 39;
	Solution solu;
	cout << solu.minOperations2(n) << endl; 
	
	return 0;
}
