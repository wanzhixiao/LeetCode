#include<iostream>
#include<vector>
#include<unordered_map> 
using namespace std; 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		int n = nums.size();
		vector<int> presum(n+1,0);
		
		for (int i = 1; i <= n; i++) {
			int num = (nums[i-1] == 0) ? -1 : 1;
			presum[i] = presum[i-1] + num;
		}
		unordered_map<int,int> m{{0,0}};
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int target = presum[i];
			if (m.count(target)) {
				ans = ans > (i-m[target]) ? ans : (i-m[target]);
			} else {
				m[target] = i;
			}
		}
		return ans;
    }
};

int main() {
	vector<int> nums = {0,1};
	Solution s;
	cout << s.findMaxLength(nums) << endl;
	return 0;
}
