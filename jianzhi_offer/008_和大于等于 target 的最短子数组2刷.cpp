#include<iostream>
#include<vector>

using namespace std;
/*
思路1：滑动窗口
窗口内的子数组满足 sum >= target
何时移动左指针？ 当sum >= target; left=left+1
何时移动右指针？ 当sum < target

注意，在移动左指针之前比较 ans = min(ans,right-left+1);
ans 需要初始化成整数最大值 0x3f3f3f3f 
*/ 
class Solution {
public:
       int minSubArrayLen(int target, vector<int>& nums) {
           int n = nums.size();
           int l = 0, r = 0;
           int sum = 0;
           int ans = 0x3f3f3f3f;
           while (r < n) {
               sum += nums[r];
                while (sum >= target) {
                    ans = ans < (r-l+1) ? ans : (r-l+1);
                    sum -= nums[l];
                    l++;
                }
               r++;
           }
           return ans == 0x3f3f3f3f ? 0 : ans;
    }
};

int main() {
	
	return 0;
} 

