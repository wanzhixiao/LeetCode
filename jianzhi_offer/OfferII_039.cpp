#include<vector>
#include<iostream>
using namespace std;

int maxArea(vector<int> &nums){
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    int left = 0, right = 0;
    int ans = 0;
    int height = nums[0];

    while(right < n){
        if(nums[right] < height){
            height = nums[right];
        }
        int area = (right-left+1)*height;   //(1-0+1) * 3 = 6
        if(area > ans){
            ans = area;
        }
        else
        {
            left = right;
        }
        right++;
    }
    return ans;
}

int main() {
    int nums[] =  {5,3,1,2,3};
    vector<int> arr(nums,nums+sizeof(nums)/sizeof(int));
    int ans = maxArea(arr); 
    cout << sizeof(int) << endl;
	return 0;
}

/*
[5,3,1,2,3]
*/

/*
https://leetcode.cn/problems/container-with-most-water/
https://leetcode.cn/problems/largest-rectangle-in-histogram/
https://leetcode.cn/problems/0ynMMM/solution/xiang-xi-shuo-shuo-ru-he-cong-bao-li-fa-gusww/
*/