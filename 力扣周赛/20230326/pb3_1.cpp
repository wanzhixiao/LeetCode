#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        vector<long long> presum(n+1, 0);
        presum[0] = 0;
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i-1] + nums[i-1];
        }
        for (int i = 0, m = queries.size(); i < m; i++) {
            long long idx = binarySearch(nums, queries[i]);             // ʹ��long long
            long long  left = idx*queries[i]-presum[idx];               //�������Խ��
            long long  right = (presum[n]-presum[idx]) - (n-idx)*queries[i];
            ans.push_back(left + right);
        }
        
        return ans;
    }
    
    int binarySearch(vector<int> &nums, int target) {
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
};

/*
1. ����
2. ��ǰ׺��
3. ����ÿ��querie, �ҵ�nums�е�һ������queries[i]��Ԫ�ص��±�idx
4. ������������ left = querie[i] * idx = presum[idx];
5. �����Ҳ������ right = presum[n]-presum[idx] - (n-idx) * queries[i]
6. ��ǰquerie�Ĳ����� = left + right

���룺nums = [3,1,6,8], queries = [1,5]
�����[14,10]

1 3 6 8
1 4 10 18

1. ��Ͱ��ͳ��ÿ��Ͱ�ڶ�Ӧ�������±꣬   key:num, value: [idx1,idx2...]
2. ����ÿ��Ͱ
    2.1����ÿ��Ͱ��ǰ׺��
    2.2����Ͱ��ÿ��Ԫ��item��
        ��һ������item���±�idx
        ����ֵ = item * idx - presum[idx] : ���������-��״���
        �Ҳ��ֵ = presum[n]-(n-idx)*item-presum[idx]
        ��ֵ���Ժ� = ����ֵ + �Ҳ��ֵ


https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/solution/yi-tu-miao-dong-pai-xu-qian-zhui-he-er-f-nf55/   
*/

int main() {
	Solution solu;
	vector<int> nums{2,9,6,3}, queries{10};
	vector<long long> ans = solu.minOperations(nums,queries);
	for (auto x : ans) {
		cout << x << " "; 
	}
	cout << endl;
	return 0;
}
