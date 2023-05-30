#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
思路1：贪心法
	判断nums[i] > nums[i-1] ; cnt++; 否则 cnt=1; ans = max(ans,cnt);   
	注意连续递增的case,  需要在循环遍历结束 ans = max(ans,cnt)
思路2：dfs
	[1,3,5,4,7]
	
	从3开始搜索， 遇到4 < 5 : 返回0到上一层 
	若nums[i]>nums[i-1]返回 1 + dfs(nums,i+1)到上一层 
	
	递归的终止条件是 i == nums.size() 
思路3：单调栈
	维护一个单调递增栈，
	每次push一个元素，ans = max(ans,stk.size()) 
	当栈顶元素>=nums[right]; right>stk.top(), 则清空栈
	 
*/

class Solution {
public:
    int result = 1;
    int dfs(vector<int>& nums, int i) {
        if (i == nums.size()) {
            return 0;
        }
        int temp = 1 + dfs(nums, i + 1);
        result = max(temp, result);
        return nums[i] > nums[i - 1] ? temp : 0;
    }

    int findLengthOfLCIS(vector<int>& nums) {
        int temp = 1 + dfs(nums, 1);
        result = max(temp, result);
        return result;
    }
    
    int findLengthOfLCIS2(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                cnt++;
            } else {
                ans = max(ans,cnt);
                cnt = 1;
            }
        }
        ans = max(cnt,ans);
        return ans;
    }
    
    int findLengthOfLCIS3(vector<int>& nums) {
    	stack<int> stk;
        int i = 0, result = 1;;
        while(i < nums.size()) {
            stk.push(i);
            result = result > stk.size() ? result : stk.size();
            i++;
            if(i>=nums.size()) {break;}
            if(nums[stk.top()] >= nums[i]) {
                while (!stk.empty()){
                    stk.pop();
                }
            }
        }
        return result > stk.size() ? result : stk.size();
	}
};

int main() {
	vector<int> nums = {1,3,5,4,7};
	Solution solu;
	cout << solu.findLengthOfLCIS3(nums) << endl;
	return 0;
}
