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
            long long idx = binarySearch(nums, queries[i]);             // 使用long long
            long long  left = idx*queries[i]-presum[idx];               //大数相乘越界
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
1. 排序
2. 求前缀和
3. 遍历每个querie, 找到nums中第一个大于queries[i]的元素的下标idx
4. 计算左侧操作数 left = querie[i] * idx = presum[idx];
5. 计算右侧操作数 right = presum[n]-presum[idx] - (n-idx) * queries[i]
6. 当前querie的操作数 = left + right

输入：nums = [3,1,6,8], queries = [1,5]
输出：[14,10]

1 3 6 8
1 4 10 18

1. 分桶，统计每个桶内对应的数字下标，   key:num, value: [idx1,idx2...]
2. 遍历每个桶
    2.1计算每个桶的前缀和
    2.2遍历桶内每个元素item；
        第一个大于item的下标idx
        左侧差值 = item * idx - presum[idx] : 正方形面积-柱状面积
        右侧差值 = presum[n]-(n-idx)*item-presum[idx]
        差值绝对和 = 左侧差值 + 右侧差值


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
