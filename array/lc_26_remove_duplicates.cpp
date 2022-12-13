 #include<iostream>
#include<vector>
using namespace std;

/*
保留不重复元素：思路
方法：快慢指针
慢指针指向的元素保留，快指针进行遍历，快指针遇到的是新的元素，即nums[slow] != nums[fast];  
用nums[slow]存放新的元素
1,1,2
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=1;i<n;i++){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};

int main(){
    int arr[] = {0};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    cout << "result = " << s.removeDuplicates(nums) << endl;
    return 0;
}