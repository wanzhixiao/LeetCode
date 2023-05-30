#include<vector>
#include<iostream>
using namespace std; 


/*
1 1 2 3 3 4 4 5 5

ֻ����һ�ε������Ϊx = 2��

numx[y] = numx[y+1] һ��������x����࣬yΪż�� 
numx[z] = numz[z-1] һ��������x���Ҳ࣬zΪż��

���x���±�Ϊż��������Ԫ�ظ���һ��Ϊż�����ж�

mid % 2 == 0
	if mid+1 < n && nums[mid] != nums[mid+1] , ˵������һ�ε�Ԫ����left�Ҳ� ��������mid
		right = mid
	else 
		left = mid + 1					// 
else
	if mid - 1 >= 0 && nums[mid] != nums[mid-1]
		right = mid
	else
		left = mid + 1					//mid����Ԫ��Ϊż�������Ҷ��ɶ��� 


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
