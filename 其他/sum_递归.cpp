#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<int> &nums, int pos) {
	if (pos == nums.size()-1) {
		return nums[pos];
	}
	return nums[pos] + dfs(nums, pos+1);
} 

int dfs2(vector<int> &nums, int pos) {
	if (pos == 0) {
		return nums[pos];
	}
	return nums[pos] + dfs2(nums, pos-1);
}

int sum3(vector<int> &nums) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	return sum;
}

int main() {
	vector<int> nums = {1,2,3};
	cout << sum3(nums) << endl;
	return 0;
} 
