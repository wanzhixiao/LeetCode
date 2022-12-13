#include<bits/stdc++.h>
using namespace std;


//数组有序 & 保留逻辑

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int j = 2;
        for(int i=2; i<n; i++){
            if(nums[j-2]!=nums[i]){
                 nums[j] = nums[i];
                 j++;
            }
        }
        return j;
    }
    
    int removesDuplicatesK(vector<int>& nums,int k){
        int m = this->process(nums,k);
        return m;
    }

    int process(vector<int>& nums, int k){
        int n = nums.size();
        if(n<=k){
            return n;
        }
        int j = k;
        for(int i=k; i<n;i++){
            if(nums[j-k] != nums[i]){
                nums[j] = nums[i];
                j = j+1;
            }
        }
        return j;
    }
};

int main(){
    int arr[] = {0,0,1,1,1,1,2,2,2,2,3,3};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int k = 3;
    cout << s.removesDuplicatesK(nums,k) << endl;
    return 0;
}