#include<vector>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
 
class Solution {
public:
     vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        int target = n - k;
        int left = 0, right = n - 1;
        
        while (true) {
            int pivot = partition(arr, left, right);
            if (target == pivot) {
            	for (auto &x : arr) {
					cout << x << " ";
				}
				cout << endl;
                // cout << arr[pivot] << endl;
                return vector<int>(arr.begin(), arr.begin()+k);
                // return arr[pivot];
            } else if(target > pivot) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        return {};
    }

    int partition(vector<int> &nums, int left, int right) {
        int randomIndex = left + rand()%(right-left+1);
        // int randomIndex = left;
        swap(nums, randomIndex, left);
        int i = left + 1;
        int j = right;
        int x = nums[left];

        while (true) {
            while (i <= j && nums[i] < x) {
                ++i;
            }
            while (i <= j && nums[j] > x) {
                j--;
            }
            if (i >= j) {
                break;
            }
            swap(nums, i, j);
            i++;
            j--;
        }
        swap(nums, left, j);
        return j;
    }

    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

int main() {
	vector<int> nums = {0,1,2,1};
	int k = 1;
	Solution solu;
	vector<int> ans = solu.getLeastNumbers(nums,k);
	for (auto &x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
