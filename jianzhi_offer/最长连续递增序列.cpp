#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
˼·1��̰�ķ�
	�ж�nums[i] > nums[i-1] ; cnt++; ���� cnt=1; ans = max(ans,cnt);   
	ע������������case,  ��Ҫ��ѭ���������� ans = max(ans,cnt)
˼·2��dfs
	[1,3,5,4,7]
	
	��3��ʼ������ ����4 < 5 : ����0����һ�� 
	��nums[i]>nums[i-1]���� 1 + dfs(nums,i+1)����һ�� 
	
	�ݹ����ֹ������ i == nums.size() 
˼·3������ջ
	ά��һ����������ջ��
	ÿ��pushһ��Ԫ�أ�ans = max(ans,stk.size()) 
	��ջ��Ԫ��>=nums[right]; right>stk.top(), �����ջ
	 
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
