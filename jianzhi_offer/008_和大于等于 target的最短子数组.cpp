#include<iostream>
#include<vector>
using namespace std;

/*
和大于等于target的最短子数组 
target = 7, nums = [2,3,1,2,4,3]
输出2 
解释：子数组[4,3]是满足条件的长度最短子数组

思路1：暴力法
	枚举所有子数组，在遍历过程中将子数组求和，遍历过程中和第一次大于target即跳出循环 
思路2： 滑动窗口 
思路3：前缀和+二分查找 
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int tmp = INT_MAX;
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum >= target){
                    tmp = j-i+1;
                    break;
                }
            }
            ans = ans < tmp ? ans : tmp;
        }
        return ans==INT_MAX ? 0 : ans;
    }
    
    int minSubArrayLen2(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0, right = 0, minlen = INT_MAX;
        int sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                minlen = minlen < (right-left+1) ? minlen : (right-left+1);
                sum -= nums[left];
                left++;
            }
            ans = ans < minlen ? ans : minlen;
            right ++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
    
    int minSubArrayLen3(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> presum(n,0);
        presum[0] = nums[0];
        cout << presum[0] << " ";
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1] + nums[i];
            cout << presum[i] << " ";
        }
        cout << endl;
        for(int i=0;i<n;i++){
            int num = presum[i] - target;
            int left = -1, right = n;
            while(left + 1 != right){
				int mid = left + (right-left)/2;
				if(presum[mid]<=num){
					left = mid;
				} 
				else
				{
					right = mid;
				}
            }
            if(left != -1)
			{
				ans = ans < (i-left) ? ans : (i-left);
            
			}
			cout << num << " " << i << " " << left << endl;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};

int main()
{
	vector<int> nums={2,3,1,1,1,1,1};
	int target = 5;
	Solution s;
	cout << s.minSubArrayLen3(target,nums) << endl;
	return 0;
}
