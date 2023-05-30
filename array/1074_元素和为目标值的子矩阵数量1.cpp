#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std; 


/*
枚举行的起点i = 0 to n
行的终点j = i to n

再枚举纵向 k = 0 to n，将sum[k] += matrix[j][k];

然后再将 s += sum[i]就可以得到子矩阵的和； sum[i]代表的是列的和, s将列加起来得到子矩阵的和 
*/
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		int ans = 0;
		for (int i = 0; i < m; i++) {
			vector<int> sum(n,0); 
			for (int j = i; j < m; j++) {
				for (int k = 0; k < n; k++) {
					sum[k] += matrix[j][k];
				}
				ans += subarraySum(sum,target);
			}
		}
		return ans;
    }
    
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp{{0,1}};
        int sum = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            sum += nums[i-1];
            int target = sum - k;
            if(mp.count(target)) {
                ans += mp[target];
            }
            ++mp[sum];
        }
        return ans;
    }
};

int main() {
	vector<vector<int>> matrix = {{0,1,0},{1,1,1},{0,1,0}};
	int target = 0;
	Solution s;
	cout << s.numSubmatrixSumTarget(matrix,target) << endl; 
	return 0;
}
