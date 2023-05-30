#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
	/*
	下一个排列
	要把后面较大的数放到前面去 
	*/
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size()-1;
        //2 4 5 3 1
        // 4 < 5; k = 2
        while (k > 0 && nums[k-1] >= nums[k]) {
            k--;
        }
        if (k <= 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int t = nums.size()-1;
            // 2 4 5 3 1
            // 3 
            while (nums[t] <= nums[k-1]) {
                // cout << nums[t] << " " << nums[k-1] << endl;
                t--;
            }
            // cout << "t=" << nums[t] << " k=" << nums[k-1] << endl;
            swap(nums, t, k-1);
            reverse(nums.begin()+k, nums.end());
        }
    }
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

class Solution2 {
	/*
	1053 前一个排列
	把大的数放到后面去 
	1. 找到第一个降序的位置 a[i-1]>a[i]
	2. 将a[i-1]与 i...n-1中最接近a[i-1]的数a[k]交换， (a[k]<a[i-1]) 
	*/
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n - 1;
        //[1,9,4,6,7]
        //找到一个降序的位置A[i-1]
        while (i > 0 && arr[i] >= arr[i-1]) {
            i--;
        }   
        if (i == 0) {
            return arr;
        }
        //把A[i]后面的数字中，小于A[i]且最接近A[i]的值的数字找出来，和A[i]交换。
        int left = i-1;
        int right = i;
        while (true) {
            if (i+1 < n && arr[i+1] < arr[left]) {
                i++;
                if (arr[i] > arr[right]) {
                    right = i;
                }
            } else {
                int t = arr[right];
                arr[right] = arr[left];
                arr[left] = t;
                break;
            }
        }
        return arr;
    }
};

int main() {
	vector<int> nums = {2,4,6,5,1};
	Solution solu;
	solu.nextPermutation(nums);
	//2 5 1 4 6
	for (int x : nums) {
		cout << x << " ";
	}
	return 0;
} 

/*
1 2 3 4 6 5
1 2 3 5 4 6 
思路：
 
*/
