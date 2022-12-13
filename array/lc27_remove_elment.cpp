#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        //1.定义slow和fast指针
        int slow=0,fast=n;
        //2.快指针先走，
        while(slow<fast){
            if(nums[slow] == val){
                nums[slow]  = nums[fast-1];
                fast--;
            }
            else{
                slow++;
            }
            //当nums[fast] != nums[slow]
            cout << slow << " " << fast <<" " << nums[slow] << " " << nums[fast] << endl;
        }

        return slow;
    }

    int removeElement1(vector<int>& nums, int val) {
        
        int n = nums.size();
        //1.定义slow和fast指针
        int slow = 0;
        //2.快指针先走，
        for(int fast=0; fast<n; fast++){
            if(nums[fast]!=val){
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;
    }
};

int main(){
    int arr[] = {3,2,2,3};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int val = 3;
    Solution s;
    cout << "result = " << s.removeElement1(nums,val) << endl;
    return 0;
}