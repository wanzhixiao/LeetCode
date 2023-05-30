#include<vector>
#include<iostream>
using namespace std; 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    	int n = arr.size();
        int left = 1, right = n-2;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
//            if (mid == 0) {
//            	left = mid + 1;
//            	continue;
//			} 
//            if (mid == n - 1) {
//            	right = mid - 1;
//            	continue;
//			}
            
            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid;
            }

            if (arr[mid] < arr[mid+1]) {
                left = mid + 1;
            } else if (arr[mid] < arr[mid-1]) {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
	vector<int> nums = {3,5,3,2,0};
	Solution solu;
	cout << solu.peakIndexInMountainArray(nums) << endl;
	return 0;
}
