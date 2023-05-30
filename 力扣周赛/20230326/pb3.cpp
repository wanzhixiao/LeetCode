#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;

int minOpers = INT_MAX;

int dfs(int n, int target) {
	if (n == target) {
		return 0;
	}
	int plus = INT_MAX, minus = INT_MAX;
	if (n < target) {
		plus = dfs(n + 1, target);
		
	}
	if (n > target) {
		minus = dfs(n - 1, target);
	}
	return 1 + min(plus, minus);
}

//21 / 31
vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    vector<LL> ans;
	int opers = 0;
	
	for (int j = 0, m = queries.size(); j < m; j++) {
		int numOpers = 0;
		for (int i = 0, n = nums.size(); i < n; i++) {
			if (nums[i] != queries[j]) {
				numOpers += abs(nums[i]-queries[j]);
			}
		}
		ans.push_back(numOpers);
	}
	return ans;
}

class Solution {
private:
    typedef long long LL;
    int mod = 1e9;
public:
	////24 / 31
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<LL> ans;
        int n=nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum%mod + nums[i]%mod)%mod;
        }
        
        for (int j = 0, m = queries.size(); j < m; j++) {
            unsigned long long a = (n*queries[j])%mod;
            unsigned long long numOpers = ((sum-a) < 0) ? -(sum-a) : (sum-a);
            // for (int i = 0, n = nums.size(); i < n; i++) {
            //     if (nums[i] != queries[j]) {
            //         numOpers += abs(nums[i]-queries[j]);
            //     }
            // }
            
            ans.push_back(numOpers);
        }
        return ans;
    }
};

int main() {
	vector<int> nums = {2,9,6,3};
	vector<int> queries = {10};
	vector<long long> ans = minOperations(nums,queries);
	for (LL x : ans) {
		cout << x << " ";
	}
	cout << endl;
//	cout << dfs(8,5) << endl;
	return 0;
} 
