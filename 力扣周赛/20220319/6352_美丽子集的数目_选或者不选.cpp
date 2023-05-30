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
        	//ö��ѡ�ĸ� 
            ans += 1;
            if (pos == nums.size()) {
            	//ans += 1;						//ѡ��ѡ 
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
�Ӽ��ͻ���
1. ѡ���߲�ѡnums[i], ��Ҫ������Ԫ�������꣬��ѡ���ʱ���������֦
2. ö��ѡ�ĸ�����·���ϰѵ�ǰѡ��Ԫ�ؼ������� 


����Ǵ�������ѡ������Ԫ�أ�����Խ� 
*/ 

