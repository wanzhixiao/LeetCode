#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*
最小最大化
给定一个尝试的区间，求解最小的最大值k，
如果最大值k满足check条件，右指针左移，减小k
如果最大值k不满足check条件，左指针右移，增加k

我们需要求得一个最小的最大值	k 
*/ 

class Solution {
public:
  	int minimizeArrayValue(vector<int>& nums) {
            int left = 0, right = *max_element(nums.begin(), nums.end());
            while (left < right){ //[left, right)
                int mid = left + (right-left)/2;
                cout << left << " " << mid << " " << right << endl;
                if (check(mid,nums)) {
                    right = mid;
                } else {
                    left = mid+1;
                }
            }
        return left;
    }

    bool check(int limit, vector<int> nums) {
    	int n = nums.size();
    	//将整形数组转为longlong形，防止越界 
        vector<long long> A(n,0);
        for (int i = 0; i < n; i++) {
            A[i] = nums[i];
        }

        long long extra = 0;
    	for (int i = n-1; i >= 1; i--) {
            if (A[i] > limit) {
                long long det = A[i] - limit;		//后一个数减去当前尝试的值 
                A[i] = limit;						//当前的数等于尝试的值 
                A[i-1] += det;						//前一个数加上尝试的值 
            }
		}
		printVec(A); 
		return A[0] <= limit;
	}
	
	bool check2(int limit, vector<int> &nums) {
		int n = nums.size();
        long long tmp = 0;
        for (int i = n-1; i >= 1; i--) {
            if (nums[i]+tmp > limit) {
                tmp = nums[i] - limit;
            } else {
                tmp = 0;
            }
        }
        return nums[0] + tmp <= limit;
	} 
	
    void printVec(vector<long long> &nums) {
    	for (int i = 0; i < nums.size(); i++) {
    		cout << nums[i] << " ";
		}
		cout << endl;
	}
  
};

int main() {
	vector<int> nums = {3,7,1,6};
	Solution solu;
	cout << solu.minimizeArrayValue(nums) << endl;
	return 0;
}
