#include<iostream>
#include<vector>
using namespace std; 

/*

560. 和为 K 的子数组
输入：nums = [1,1,1], k = 2
输出：2

输入：nums = [1,2,3], k = 3
输出：2

0..i...j
sum[0...i-1] == sum[0...j] , 则sum[i...j] = 0 
和为k的子数组
用Map记录前缀和出现的次数，
target = sum - k;

如果target在map中出现过，说明 sum[i...j]这段的和 为k 
1 1 1 ， k = 2

sum = 0 1 2 3, k = 2
target = 0,-1,0,1
初始化mp[0] = 1


0 1 2 3
	1-2 = -1 sum - k = target		++mp[sum]
	2-2 = 0  sum - k = target		++mp[sum] 
	3-1 = 0	 sum - k = target		++mp[sum]
	记录每个前缀和出现了多少次，target在mp出现过，则之前的 sum = target ， ans += mp[sum]; 再++mp[sum] 
*/

class Solution {
public:
	//560. 和为 K 的子数组	//930. 和相同的二元子数组
	/*
		nums[0...i....j]
		sum[0...i] - k == sum[0...j] - k, sum[i...j] = 0
		
		希望 
		preSumj - (preSumi - k) == k 
		即 
		presum[j] - k == presum[i]-k
		
		在计算presum[j]时，需要记录已经记录了多少个presum[presum[j]-k] , 即presum[presum[i]-k] 
	*/ 
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mp{{0,1}};			//key是前缀和， value是前缀和出现的次数 
        for (int i = 1; i <= n; i++) {
            sum += nums[i-1];
            int target = sum - k;
            if (mp.find(target) != mp.end()) {
                ans += mp[target];
            }
            ++mp[sum];
        }
        return ans;
    }
    //https://leetcode.cn/problems/subarray-sums-divisible-by-k/solution/de-liao-wo-ba-qian-zhui-he-ba-de-gan-gan-ngkp/
    
    //974. 和可被 K 整除的子数组
    // mod = presum[j]%k == presum[i]%k 
    /*
		输入：nums = [4,5,0,-2,-3,1], k = 5
		输出：7 
	*/ 
    int subarraysDivByK(vector<int>& nums, int k) {
    	int n = 0, sum = 0;
		unordered_map<int,int> mp{{0,1}};			//key是余数， value是余数出现的次数 
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			int mod = ((sum%k)+k)%k;
			if (mp.count(mod)) {
				ans += mp[mod];
			}
			++mp[mod];
		}
		return ans;
    }
    
    //1590. 使数组和能被 P 整除
    // 思路： 算总和 sum ， sum % p = mod;  如果mod != 0, 即从数组中找出一些元素组成的最短子数组，使得其和等于mod 
     int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        // 细节： accumulate使用0LL函数
        int mod = accumulate(nums.begin(), nums.end(), 0LL) % p;

        // long long sum = 0;
        // for (int i = 0; i < n; i++) {
        //     sum = sum+nums[i];
        // }
        // int mod = sum % p;
        if (mod == 0) {
            return 0;
        }
        // if (sum < p) {
        //     return -1;
        // }
        int presum = 0;
        unordered_map<int, int> mp{{0,-1}};         // key: sum, value: position
        // presum[j] - (presum[i]-mod) == mod       => presum[j]-mod == presum[i] - mod
        int minlen = n;
        for (int i = 0; i < n; i++) {
            //   s = (s + nums[i]) % p;
            presum = (presum + nums[i])%p;
            mp[presum] = i;

            // int target = presum - mod;

            //为了避免判断 mod 是否为负数，target可以写成
            //auto it = last.find((s - x + p) % p);
            int target = (presum - mod + p) % p;

            // cout << presum << " " << target << " " << mod << " " << mp[target]<< endl;
            if (mp.find(target) != mp.end()) {
                if (i - mp[target] < minlen){
                    minlen = i - mp[target];
                }
            }

        }
        return minlen == n ? -1 : minlen;
    }
    
    //523 连续的子数组和 
   	//presum[j] - presum[i]为k的倍数，则presum[j]%k == presum[i]%k  = mod
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = nums[0];
        unordered_map<int,int> mp{{sum%k,0}};       //key 余数，value位置

        for (int i = 1; i < n; i++) {
            sum += nums[i];
            int mod = sum % k;
            if (mod == 0) {
                return true;
            }
            else if (mp.count(mod)) {
                if (i-mp[mod] >= 2) {
                    return true;
                }
            } else {
                mp[mod] = i;
            }
        }
        return false;
    }
    
    // 525 连续数组 
    //我们可以将数组中的 0视作 ?1，则原问题转换成「求最长的连续子数组，其元素和为 0 
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int sum = 0, ans = 0;
        //细节1 规定空的前缀的结束下标为 -1， 由于空的前缀的元素和为 0
        
        unordered_map<int,int> mp{{0,-1}};
        for (int i = 0; i < n; i++) {
            sum += ((nums[i] == 1) ? 1 : -1);
            if (mp.count(sum)) {
                ans = max(ans, i - mp[sum]);
            }
            else mp[sum] = i;
        }
        return ans;
    }
   	//https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/solution/tao-lu-qian-zhui-he-ha-xi-biao-pythonjav-3fna/ 
};

int main() {
	
	return 0;
} 
