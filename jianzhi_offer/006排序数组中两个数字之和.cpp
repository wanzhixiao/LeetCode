#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*
从排序数组中找到两个数，使得两个数之和=targetSum, 输出这两个数的下标
输入 ： numbers = [1,2,4,6,10], target = 8 
输出：[1,3]

思路1：双指针 , 时间复杂度 O(n) 
思路2：二分查找 , 时间复杂度 O(nlogn) 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n-1;
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                return {left, right};
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else
            {
                left++;
            }
        }
        return {left,right};
    }
    
    vector<int> twoSum2(vector<int>& numbers, int target) {
    	int n = numbers.size();
    	for (int i = 0; i < n; i++) {
    		int num = target - numbers[i];
    		int left = i + 1, right = n - 1;
    		while (left <= right) {
    			int mid = left + (right - left)/2;
    			if (numbers[mid] == num) {
    				return {i, mid};
				} else if (numbers[mid] > num) {
					right = mid - 1; 
				} else {
					left = mid + 1;
				}
			}
		}
		return {0,1};
	}
};

int main(){
	
} 
