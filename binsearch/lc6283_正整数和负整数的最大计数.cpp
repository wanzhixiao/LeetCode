#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int negative = binary_search1(nums,0);
        int positive = binary_search2(nums,0);
        if (nums[negative] == 0 && nums[positive] == 0) {
        	return 0;
		}
        int ans = negative + 1 > n-positive ? negative + 1 : n-positive;
        return ans;
    }
    
    int binary_search1(vector<int> &nums, int target) { 
	    int left = -1, right = nums.size();
    	while (left + 1 != right) {
    		int mid = (left + right)/2;
    		if (nums[mid] < target) {
    			left = mid;
			} else {
				right = mid;
			}
		}
		return left == -1 ? 0 : left; 
	}
    
    int binary_search2(vector<int> &nums, int target) {
    	int left = -1, right = nums.size();
    	while (left + 1 != right) {
    		int mid = (left + right)/2;
    		if (nums[mid] <= target) {
    			left = mid;
			} else {
				right = mid;
			}
		}
		return right == nums.size() ? right - 1 : right; 
	}
};

int main() {
	vector<int> nums = {0};
	Solution solu;
	cout << solu.maximumCount(nums) << endl; 
	return 0;
} 
