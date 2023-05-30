#include<iostream>
#include<vector>
using namespace std;


/*
lowerboud [1,2,3,4,7,8,8,9]  ,query = 8, 返回第一个8的下标5
第一种，左闭右闭区间 [left,right]
初始化 left = 0, right = n-1

第二种，将区间的左端点或者右端点初始化成开区间	[left,right), 或者(left,right]

第三种，左开右开区间 (left,right) 
left = -1, right = n
*/
int binary_search1(vector<int> &nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {					//区间不为空 
		int mid = left + (right - left ) / 2;
		if (nums[mid] < target) {
			left = mid + 1;					//[mid+1,right] 
		} else {
			right = mid - 1;				//[left, mid-1]
		}
	}
	return left;
}

int binary_search2(vector<int> &nums, int target) {
	int left = 0, right = nums.size();		//左闭右开区间[left,right) 
	while (left < right) {					//区间不为空 
		int mid = left + (right - left ) / 2;
		if (nums[mid] < target) {
			left = mid + 1;					//[mid+1,right) 
		} else {
			right = mid;				//[left, mid)
		}
	}
	return left;  //或者return right, 因为while退出时left = right 
}

int binary_search3(vector<int> &nums, int target) {
	int left = -1, right = nums.size();		//左开右开区间(left,right) 
	while (left + 1 < right) {				//区间不为空 
		int mid = left + (right - left ) / 2;
		if (nums[mid] < target) {
			left = mid;						//(mid,right) 
		} else {
			right = mid;					//(left, mid)
		}
	}
	return right;  //或者return right, 因为while退出时left = right 
}


int main() {
	vector<int> nums = {1,2,3,4,7,8,8,9};
	int target = 8;
	cout <<binary_search1(nums,target) << endl;
	cout <<binary_search2(nums,target) << endl;
	cout <<binary_search3(nums,target) << endl;
	return 0;
}
