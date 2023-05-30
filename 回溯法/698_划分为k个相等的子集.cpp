#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<vector<int>> vv; 
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    	if(nums.size() < k){
    		return false;
		}

		int sum = 0;
		for(int i=0; i<nums.size(); i++){
			sum += nums[i];
		}
		
		if(sum % k != 0){
			return false;
		}
		
		sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
		
        if(nums[0] > sum/k){
            return false;
        }

		int target = sum/k;
		
		vector<bool> used(nums.size(),false);
		
		bool result = backtrack(nums,used,k,0,target);
		
		
		return result; 
    }
    
    bool backtrack(vector<int> &nums,vector<bool> &used, int k, int cur,int target){
    	
    	if(k == 0){
    		return true;
		}
		
		 // 这个子集分配完毕了，递归
        if(cur == target){
            return backtrack(nums, used,  k-1,0, target);
        }
    	
    	for(int i=0; i < nums.size(); i++){
            if(nums[i] > target - cur){
                continue;
            }
    		if(!used[i]){
    			used[i] = true;
    			cur += nums[i];
    			
    			if(backtrack(nums,used,k,cur,target)){
    				return true;
				}
    			
    			used[i] = false;
    			cur -= nums[i]; 
			}
		}
        return false;
	} 
};


int main()
{
//	[2,2,2,2,3,4,5]
	
	vector<int> v{4, 3, 2, 3, 5, 2, 1};
	int k = 4;
	Solution solu;
	cout << solu.canPartitionKSubsets(v, k) << endl;
	
	return 0;
} 


