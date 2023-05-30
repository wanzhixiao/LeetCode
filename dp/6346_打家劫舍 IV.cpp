#include<iostream>
#include<vector>
using namespace std;

/*
题目：6346
思路：最小化最大值
	有序的量：窃取能力，nums中的值的最大值 tmax; [0, tmax] 形成了一个递增的搜索序列
	尝试[0,tmax]中的每个值t, 使得t越小；
	
	二分 ： 如果满足check()条件，则减小t , right = mid;
		    如果不满足check()条件，增加t, left = mid; 
		
	问题2： 如何实现check()
			（1）相邻的房屋不能偷
			（2）对于第i间房，可以选择偷或者不偷，如果偷，则需要满足偷盗的能力cap >= nums[i]
			（3）check需要返回的是 当遍历完nums中的所有数时， 能偷盗的房屋数是否满足 >= k ? 
题目：198 打家劫舍
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
    			dp[i+2] = max(dp[i+2],dp[i]+1);         //偷和不偷取最大
			}
		}
		return dp[n+1] >= k; 
    }   
    
    //check 数组空间复杂度优化 
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
1. 二分查找，查找非连续数字的最小值
2.用数组的最小值和最大值作为查询范围
3.实现一个check函数，判断是否能选出k个不连续的元素，使得所有元素不超过当前猜的元素
4.根据check函数的输出挑战搜索的范围，直到这个range收敛以及最小值已经找到
*/

int main() {
	vector<int> nums = {2,3,5,9};
	int k = 2;
	Solution solu;
	cout << solu.minCapability(nums,k) << endl;
	return 0;
}
