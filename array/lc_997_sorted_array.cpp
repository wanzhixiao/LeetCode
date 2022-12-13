#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    for(int i=0; i<n; i++){
        nums[i] = nums[i]*nums[i];
    }
    sort(nums.begin(),nums.end());
    return nums;
}

void printVector(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {-4,-1,0,3,10};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
    vector<int> result = sortedSquares(nums);
    printVector(nums);
    return 0;
}