#include<bits/stdc++.h>
using namespace std;

int mergeSum(vector<int> &nums, int left, int right) {
	if (left >= right) {
		return nums[left];
	}
	int mid = (left + right) / 2;
	int lsum = mergeSum(nums, left, mid);
	int rsum = mergeSum(nums, mid+1, right);
	return lsum + rsum;
}

int dfs(vector<int> &nums, int i, int n) {
	if (i == n) {
		return 0;
	}
	return dfs(nums, i+1, n) + nums[i];
}

/*
			0 1 2 3 4
			/    \
		0 1 2    3 4
	  0 1   2   3   4
       1    2     
         3        7
             10
*/


int main() {
	vector<int> nums = {0,1,2,3,4};
	int ans = mergeSum(nums, 0, nums.size()-1);
	int ans2 = dfs(nums,0,nums.size());
	cout << ans << " " << ans2 << endl;
	return 0;
} 


