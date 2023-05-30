#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std; 


/*
ö���е����i = 0 to n
�е��յ�j = i to n

��ö������ k = 0 to n����sum[k] += matrix[j][k];

Ȼ���ٽ� s += sum[i]�Ϳ��Եõ��Ӿ���ĺͣ� sum[i]��������еĺ�, s���м������õ��Ӿ���ĺ� 
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
