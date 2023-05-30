#include<iostream>
#include<vector>
using namespace std; 

class Solution {
private:
    unordered_map<int,int> m;
    int ans = 0;
public:
        int beautifulSubsets(vector<int>& nums, int k) {
            dfs(nums,k,0);
            return ans-1;
        }
    
        void dfs(vector<int> &nums, int k, int pos) {
        	//枚举选哪个 
            ans += 1;
            if (pos == nums.size()) {
            	//ans += 1;						//选或不选 
                return;
            }
//             dfs(nums, k, pos+1);
//             if (m[nums[pos]-k] == 0 && m[nums[pos]+k] == 0) {
//                 ++m[nums[pos]];
//                 dfs(nums, k, pos+1);
//                 --m[nums[pos]];
//             }
            for(int i = pos; i < nums.size(); i++) {
                if (m[nums[i]-k] == 0 && m[nums[i]+k] == 0){
                    ++m[nums[i]];
                    dfs(nums,k,i+1);
                    --m[nums[i]];
                }                
            }
        }
};

/*
子集型回溯
1. 选或者不选nums[i], 需要把所有元素搜索完，在选择的时候可以做剪枝
2. 枚举选哪个，在路径上把当前选的元素加入结果集 


如果是从数组中选择两个元素，则可以将 
*/ 

