class Solution {
/*
˼·���ҳ������Сֵ���Ҳ����ֵ�� �ҳ���С��i, ʹ��leftMax[i] <= rightMin[i] 
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

    //     // �ж�nums[0...j]�е�ÿ��Ԫ�ض�С��nums[j...n-1];
    //     // �ȼ����ҳ�nums[0...j]�е����Ԫ�� a, �ҳ�nums[j...n-1]�е���СԪ��b
    //     // �ж�a�Ƿ�С��b
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
 [5,0,3,8,6] ,leftMax ��5������8��������6�� leftMax = 
*/
