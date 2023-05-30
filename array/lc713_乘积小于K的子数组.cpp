#include<iostream>
#include<vector>
using namespace std;


/*
	nums = [1,1,1]
	k = 1
	
	���ڴ���ʲô��
		���������ֵĳ˻�
	��α�ʾ�� 
		product
	ʲôʱ����չ���ڣ� 
		product < k
	ʲôʱ����������
		product >= k
	�������ڵĳ˻����� product < k, ������˵�Ϊleft, �Ҷ˿�Ϊrightʱ�������������Ϊ���٣�
	nums[left...right]
	nums[right-1,right],nums[right-2,right],...,nums[right-k,right], nums[left,left+1,...,right-1,rgiht]
	��left��rightһ����right-left+1��������������
	
https://leetcode.cn/problems/subarray-product-less-than-k/solution/cheng-ji-xiao-yu-k-de-zi-shu-zu-by-leetc-92wl/ 
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            return 0;
        }
        long long product = 1;
        int left = 0, right = 0;
        int ans = 0;
        while (right < n) {
            product *= nums[right];
            while(product >= k && left <= right) {		//left <= right ; product/nums[left] >= k
                product /= nums[left];
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};

int main() {
	vector<int> nums = {10,5,2,6};
	int k = 100;
	
	Solution s; 
	cout << s.numSubarrayProductLessThanK(nums, k) << endl;
	return 0;
}

/*
 nums = [10,5,2,6], k = 100
*/
