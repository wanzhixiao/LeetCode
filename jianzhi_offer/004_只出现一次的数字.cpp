#include<iostream>
#include<vector>
using namespace std;


/*
����һ�����飬�ҳ�ֻ����һ�ε����� 
nums = [2,2,3,2]
�����3 

˼·1���½�һ��map����¼ÿ�����Ĵ�����
ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
 
˼·2��λ����
	������������ nums[i-1]^nums[i]==1 && nums[i]^nums[i+1]==1 
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
