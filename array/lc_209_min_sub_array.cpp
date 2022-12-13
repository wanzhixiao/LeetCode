#include<iostream>
#include<vector>
using namespace std;

/*
长度最小子数组
问题：给定一个数组，从中选取一个连续的子数组，使得该子数组的和sum>=target,返回该子数组的长度
    思路1：暴力解法，枚举出所有子数组，判断这些子数组的和是否>target, 并求长度最小的那一个子数组
   
    思路2：使用滑动窗口
    使用左右两个指针，遍历子数组；右指针不断往前加；过程中
    判断窗口内的和是否>=target,是则求其长度，赋值给这个窗口的最小长度； 

    窗口内是什么？                     满足>=target长度最小的子数组
    如何移动窗口的起始位置？            如果窗口的和大于target, 窗口需要缩小，左指针右移
    如何移动窗口的结束位置？            窗口结束位置就是遍历数组的指针

    窗口内最后一次满足sum>=target的子数组长度，去更新结果的长度
    输入：target = 7, nums = [2,3,1,2,4,3]；输出：2
*/

int minSubArrayLen1(int target, vector<int>& nums){
    int n = nums.size();
    int sum = 0,minlen = n+1;
    for(int i=0; i<n; i++){
        sum += nums[i];
    }
    if(sum < target){
        return 0;
    }
    sum = 0;
    int result = n+1;
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            if(sum >= target){
                minlen = j-i+1;
                result = min(minlen,result);
                break;
            }
        }
    }
    return result;
}

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int sum = 0,minlen = n+1;
    for(int i=0; i<n; i++){
        sum += nums[i];
    }
    if(sum < target){
        return 0;
    }
    sum = 0;
    int result = n+1;
    for(int i=0,j=0;j<n;j++){
        sum += nums[j];
        while(sum >= target){
            minlen = min(minlen,(j-i+1));
            sum -= nums[i];
            i++;
        }
        result = min(result,minlen);
    }
    return result;
}

int main(){
    // int target = 7;
    // int arr[] = {2,3,1,2,4,3};

    int target = 20;
    int arr[] = {2,16,14,15};

    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));

    cout << minSubArrayLen1(target,nums) << endl;
    return 0;
}