#include<vector>
#include<iostream>
using namespace std; 


/*
1 1 2 3 3 4 4 5 5

只出现一次的这个数为x = 2，

numx[y] = numx[y+1] 一定出现于x的左侧，y为偶数 
numx[z] = numz[z-1] 一定出现于x的右侧，z为偶数

如果x的下标为偶数，左侧的元素个数一定为偶数个判读

mid % 2 == 0
	if mid+1 < n && nums[mid] != nums[mid+1] , 说明出现一次的元素在left右侧 ；可能是mid
		right = mid
	else 
		left = mid + 1					// 
else
	if mid - 1 >= 0 && nums[mid] != nums[mid-1]
		right = mid
	else
		left = mid + 1					//mid左侧的元素为偶数个，且都成对了 


*/ 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size();
		int left = 0, right = n-1;
		
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (mid % 2 == 0) {
				if (mid + 1 < n && nums[mid] != nums[mid+1]) {
					right = mid;
				} else {
					left = mid + 1;
				}
			} else {
				if (mid - 1 >= 0 && nums[mid] != nums[mid-1]) {
					right = mid;
				} else {
					left = mid + 1;
				}
			}
		}
		return nums[left];
    }
};

int main() {
	vector<int> nums = {3,3,7,7,10,11,11};
	Solution solu;
	cout << solu.singleNonDuplicate(nums) << endl;
	return 0;
}
