#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
	/*
	��һ������
	Ҫ�Ѻ���ϴ�����ŵ�ǰ��ȥ 
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
	1053 ǰһ������
	�Ѵ�����ŵ�����ȥ 
	1. �ҵ���һ�������λ�� a[i-1]>a[i]
	2. ��a[i-1]�� i...n-1����ӽ�a[i-1]����a[k]������ (a[k]<a[i-1]) 
	*/
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n - 1;
        //[1,9,4,6,7]
        //�ҵ�һ�������λ��A[i-1]
        while (i > 0 && arr[i] >= arr[i-1]) {
            i--;
        }   
        if (i == 0) {
            return arr;
        }
        //��A[i]����������У�С��A[i]����ӽ�A[i]��ֵ�������ҳ�������A[i]������
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
˼·��
 
*/
