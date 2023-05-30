#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    等和分割子集：

    思路1：前缀和，用例[1,1,2,2]未通过
    nums = [2,2,1,1] -> [1,1,2,2]
    presum = [1,2,4,6]
    left    1   2   4   6
    right   5   4   2   0
    原因，不能通过有序来鉴定重复数组前半部分和后半部分相等

    思路2：回溯，数组中找一些数，使得 sum  = 2 * path_sum; 超时
    参考：树的路径和

    思路3：排序+滑动窗口
        窗口内的和的2倍 = sum;
        用例：[14,9,8,4,3,2]不通过,原因是滑动窗口内的数是连续的
            [2,3,4,8,9,14] -> 2+4+14 = 3+8+19

    思路4：动态规划
    1.确定dp数组及下标的含义
    dp[i][j]表示从[0...i]个物品中选出多个数，是否能组合成数字j
    2.递推公式
        dp[i][j] = dp[i-1][j], 如果nums[i] > j; 
        否则 dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];  是否用nums[i]来组合成数字j
    3.初始化
        dp[0][0] = 1
    4.遍历
    5.举例推导dp数组
*/


class Solution {
public:
    //方法1
    bool canPartition1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> presum(n+1,0);
        presum[0] = nums[0];
        for(int i=1;i<n;i++){
            presum[i] = nums[i] + presum[i-1];
        }
        for(int i=0;i<n;i++){
            int left = presum[i];
            int right = presum[n-1]-left;
            if(left == right){
                return true;
            }
        }
        return false;
    }

    //方法2
    bool canPartition2(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        return backtrack(nums,0,0,sum);
    }

    bool backtrack(vector<int> &nums,int j, int pathsum, int sum){
        if(j == nums.size() || pathsum > sum){
            return false;
        }
        if(2*pathsum == sum){
            return true;
        }
        int n = nums.size();
        for(int i=j;i<n;i++){
            pathsum += nums[i];
            if(2*pathsum > sum){
                continue;
            }
            bool result = backtrack(nums,i+1,pathsum,sum);
            if(result){
                return true;
            }
            pathsum -= nums[i];
        }
        return false;
    }

    //方法3，排序+双指针
    bool canPartition3(vector<int>& nums){
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        sort(nums.begin(),nums.end());
        int left = 0, right = 0, wsum = 0;
        int n = nums.size();
        while(right < n){
            wsum += nums[right];
            while(2*wsum > sum){
                wsum -= nums[left];
                left++;
            }
            if(2*wsum == sum){
                return true;
            }
            right++;
        }
        return false;
    }

    //方法4，动态规划
    bool canPartition4(vector<int>& nums){
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                if(j<nums[i-1]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n][sum/2];
    }
};

int main(){
    vector<int> vec = {2,2,1,1};
    Solution s;
    cout << s.canPartition4(vec) << endl;
    return 0;
}

/*
几个测试用例：
1.[1,5,11,5]
2.[2,2,1,1]
3.[2,2,3,5]
4.[100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97]
*/