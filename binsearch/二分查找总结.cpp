#include<iostream>
#include<vector>
using namespace std;


/*
lowerboud [1,2,3,4,7,8,8,9]  ,query = 8, ���ص�һ��8���±�5
��һ�֣�����ұ����� [left,right]
��ʼ�� left = 0, right = n-1

�ڶ��֣����������˵�����Ҷ˵��ʼ���ɿ�����	[left,right), ����(left,right]

�����֣����ҿ����� (left,right) 
left = -1, right = n
*/
int binary_search1(vector<int> &nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {					//���䲻Ϊ�� 
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
	int left = 0, right = nums.size();		//����ҿ�����[left,right) 
	while (left < right) {					//���䲻Ϊ�� 
		int mid = left + (right - left ) / 2;
		if (nums[mid] < target) {
			left = mid + 1;					//[mid+1,right) 
		} else {
			right = mid;				//[left, mid)
		}
	}
	return left;  //����return right, ��Ϊwhile�˳�ʱleft = right 
}

int binary_search3(vector<int> &nums, int target) {
	int left = -1, right = nums.size();		//���ҿ�����(left,right) 
	while (left + 1 < right) {				//���䲻Ϊ�� 
		int mid = left + (right - left ) / 2;
		if (nums[mid] < target) {
			left = mid;						//(mid,right) 
		} else {
			right = mid;					//(left, mid)
		}
	}
	return right;  //����return right, ��Ϊwhile�˳�ʱleft = right 
}


int main() {
	vector<int> nums = {1,2,3,4,7,8,8,9};
	int target = 8;
	cout <<binary_search1(nums,target) << endl;
	cout <<binary_search2(nums,target) << endl;
	cout <<binary_search3(nums,target) << endl;
	return 0;
}
