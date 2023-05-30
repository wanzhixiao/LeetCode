#include<iostream>
#include<vector>
using namespace std;

/*
��Ŀ��6346
˼·����С�����ֵ
	�����������ȡ������nums�е�ֵ�����ֵ tmax; [0, tmax] �γ���һ����������������
	����[0,tmax]�е�ÿ��ֵt, ʹ��tԽС��
	
	���� �� �������check()���������Сt , right = mid;
		    ���������check()����������t, left = mid; 
		
	����2�� ���ʵ��check()
			��1�����ڵķ��ݲ���͵
			��2�����ڵ�i�䷿������ѡ��͵���߲�͵�����͵������Ҫ����͵��������cap >= nums[i]
			��3��check��Ҫ���ص��� ��������nums�е�������ʱ�� ��͵���ķ������Ƿ����� >= k ? 
��Ŀ��198 ��ҽ���
*/ 

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int tmax = nums[0], tmin = nums[0];

        for (int i = 1; i < n; i++) {
            tmax = tmax < nums[i] ? nums[i] : tmax;
            tmin = tmin > nums[i] ? nums[i] : tmin;
        }
		// cout << tmax << " " << tmin << endl; 
        int left = 0, right = tmax+1;

        while (left + 1 < right) {  //[left, right)
            int mid = left + (right-left)/2;
			if (check(nums,k,mid)) {
				right = mid;
			} else {
				left = mid;
			}
        }
        return right;
    }

    bool check(vector<int> &nums, int k, int val) {
    	int n = nums.size();
    	vector<int> dp(n+2,0);
    	for (int i = 0; i < n; i++) {
            dp[i+2] = dp[i+1];
    		if (nums[i] <= val) {						
    			dp[i+2] = max(dp[i+2],dp[i]+1);         //͵�Ͳ�͵ȡ���
			}
		}
		return dp[n+1] >= k; 
    }   
    
    //check ����ռ临�Ӷ��Ż� 
    bool check1(vector<int> &nums, int k, int val) {
    	int n = nums.size();
        int f0 = 0;
        int f1 = 0;
    	for (int i = 0; i < n; i++) {
            if (nums[i] <= val) {
                int tmp = f1;
                f1 = max(f1,f0+1);
                f0 = tmp;
            } else {
                f0 = f1;
            }
            if (f1 >= k) {
                return true;
            }
		}
		return false; 
    }   
};

/*
tips:
1. ���ֲ��ң����ҷ��������ֵ���Сֵ
2.���������Сֵ�����ֵ��Ϊ��ѯ��Χ
3.ʵ��һ��check�������ж��Ƿ���ѡ��k����������Ԫ�أ�ʹ������Ԫ�ز�������ǰ�µ�Ԫ��
4.����check�����������ս�����ķ�Χ��ֱ�����range�����Լ���Сֵ�Ѿ��ҵ�
*/

int main() {
	vector<int> nums = {2,3,5,9};
	int k = 2;
	Solution solu;
	cout << solu.minCapability(nums,k) << endl;
	return 0;
}
