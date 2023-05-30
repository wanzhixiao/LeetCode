#include<iostream>
#include<vector>

using namespace std;
/*
˼·1����������
�����ڵ����������� sum >= target
��ʱ�ƶ���ָ�룿 ��sum >= target; left=left+1
��ʱ�ƶ���ָ�룿 ��sum < target

ע�⣬���ƶ���ָ��֮ǰ�Ƚ� ans = min(ans,right-left+1);
ans ��Ҫ��ʼ�����������ֵ 0x3f3f3f3f 
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

