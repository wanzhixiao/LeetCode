#include<iostream>
#include<vector>
using namespace std;


/*
给定一个数组，找出只出现一次的数字 
nums = [2,2,3,2]
输出：3 

思路1：新建一个map，记录每个数的次数，
时间复杂度O(n),空间复杂度O(n)
 
思路2：位运算
	三个连续的数 nums[i-1]^nums[i]==1 && nums[i]^nums[i+1]==1 
*/

int singleNumber1(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> cnt;
    for(int i=0;i<n;i++){
        cnt[nums[i]]++;
    }
    for(int i=0;i<n;i++){
        if(cnt[nums[i]]==1){
            return nums[i];
        }
    }
    return nums[0];
}

int singleNumber2(vector<int>& nums) {
	int n = nums.size();
	sort(nums.begin(),nums.end());
	for(int i=0;i<n;i++){
		if(i==0){
			if(n>1){
				if(nums[i]^nums[i+1]){
					return nums[0];
				}
			}
		}
		else if(i==n-1){
			if(n>1){
				if(nums[i]^nums[i-1]){
					return nums[i];
				}
			}
		}
		else
		{
			if(n>=3){
				if(nums[i]^nums[i-1] && nums[i]^nums[i+1]){
					return nums[i];
				}
			}
		}
	}

	return nums[0];
}

int main(){
	
	return 0;
} 
