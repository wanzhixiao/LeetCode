class Solution {
/*
思路：找出左侧最小值和右侧最大值， 找出最小的i, 使得leftMax[i] <= rightMin[i] 
*/ 
public:
    int partitionDisjoint(vector<int>& nums) {
        int left = 0, right = nums.size();
        int n = nums.size();
        vector<int> leftMax(n), rightMin(n);
        leftMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = nums[i] > leftMax[i-1] ? nums[i] : leftMax[i-1];   
        }
        rightMin[n-1] = nums[n-1];
        for (int j = n-2; j >= 0; j--) {
            rightMin[j] = nums[j+1] < rightMin[j+1] ? nums[j+1] : rightMin[j+1];
        }
        int minleft = 0;
        for (int i = 0; i < n; i++) {
            if (leftMax[i] <= rightMin[i]) {
                return i+1;
            }
            // minleft = min(minleft, i);
        }
        // int mid = 0;
        // while (left + 1 < right) {
        //     mid = left + (right-left)/2;
        //     // cout << leftMax[mid] << " " << mid << " " << rightMin[mid] << endl;
        //     if (leftMax[mid] <= rightMin[mid]) {
        //         right = mid;
        //     } else {
        //         left = mid;
        //     }
        // }
        // // cout << right << endl;
        // // cout << nums[right]  << " " << leftMax[right]<< endl;
        // return nums[right] < leftMax[right] ? right + 1 : right;
        return n-1;
    }

    // bool check(vector<int> &nums, int j, vector<int> &leftMax, vector<int> &rightMin) {

    //     // 判断nums[0...j]中的每个元素都小于nums[j...n-1];
    //     // 等价于找出nums[0...j]中的最大元素 a, 找出nums[j...n-1]中的最小元素b
    //     // 判断a是否小于b
    //     return false;
    // }
};

/*
    int partitionDisjoint(vector<int>& nums) {
        int leftMax = nums[0];
        int  min_idx = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            leftMax = leftMax < nums[i] ? nums[i] : leftMax;
  
            if (leftMax <= nums[i]) {
                min_idx = min(i, min_idx);
            } else {
                cout << leftMax << " " << i << " " << nums[i] << endl;
                min_idx = i+1;
            }
        }
        return min_idx;
    }
 [5,0,3,8,6] ,leftMax 从5更新至8，后遇到6， leftMax = 
*/
