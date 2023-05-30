#include<iostream>
#include<vector>
using namespace std;


/*
nums = [4,5,6,7,0,1,2];
[0,1,2,4,5,6,7]
target = 0;

Ê²Ã´Ê±ºòÍù×óËÑ£¬Ê²Ã´Ê±ºòÍùÓÒËÑ 

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int n = nums.size();
		
		int left = 0, right = n-1;
		
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (nums[mid] == target) {
				return mid;
			}
			
			if (nums[mid] < nums[right]) {
				if (nums[mid] < target && target <= nums[right]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			} else {
				//     4,5,6,7,0,1,2    
				if (nums[mid] > target && nums[left] <= target) {
					right = mid - 1; 
				} else {
					left = mid + 1;
				} 
			}
		}
		return -1;
    }
};

int main() {
	vector<int> nums = {3,5,1};
	int target = 3;
	
	Solution solu;
	cout << solu.search(nums, target) << endl;
	return 0;
}
