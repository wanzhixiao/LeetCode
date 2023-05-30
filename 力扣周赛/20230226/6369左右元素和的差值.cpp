#include<iostream>
#include<vector>
using namespace std;

vector<int> leftRigthDifference(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
        return {0};
    }
    vector<int> ans;
    
    vector<int> leftsum(n,0),rightsum(n,0);
    
    
    for (int i = 1; i < n; i++) {
        leftsum[i] = leftsum[i-1] + nums[i-1];
    }
    
    for (int i = n-2; i >= 0; i--) {
        rightsum[i] = rightsum[i+1] + nums[i+1];
    }
    
    for (int i = 0; i < n; i++) {
        int tmp = leftsum[i] - rightsum[i];
        tmp = tmp < 0 ? -tmp : tmp;
        ans.push_back(tmp);
    }
    return ans;
}

int main() {
	vector<int> nums = {10,4,8,3};
	vector<int> ans = leftRigthDifference(nums);
	for (int &x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
} 
