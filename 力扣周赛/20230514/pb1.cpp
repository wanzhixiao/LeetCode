#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int,int> mp;          // Key: friend, value, cnt 
        int cur = 1;
        int i = 1;
        mp[cur] = 1;
        
        while (mp[cur] != 2) {
            cur = (cur + i*k) % n;
    		if (cur == 0) {
    			cur = n;
			}
            mp[cur] += 1;
            cout << cur << " -- " << mp[cur] << endl;
            i += 1;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
        	if (mp.count(i) == 0) {
        		ans.push_back(i);
			}
		}
        return ans;
    }
    
    // 下标从0开始 ， 生成的数范围在[0,n-1]  直接对 i%n取模 ∈[0,n-1] 
    vector<int> circularGameLosers2(int n, int k) {
        unordered_map<int,int> mp;
        int cur = 0;
        int i = 1;
        mp[cur] = 1;
        
        while (mp[cur] != 2) {
            cur = (cur + i*k) % n;
            mp[cur] += 1;
            i += 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
        	if (mp.count(i) == 0) {
        		ans.push_back(i+1);
			}
		}
        return ans;
    }
};

int main() {
	Solution s;
	int n = 5, k = 2;
	vector<int> ans = s.circularGameLosers2(n,k);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
