#include<iostream>
#include<vector>
using namespace std; 

/*

560. ��Ϊ K ��������
���룺nums = [1,1,1], k = 2
�����2

���룺nums = [1,2,3], k = 3
�����2

0..i...j
sum[0...i-1] == sum[0...j] , ��sum[i...j] = 0 
��Ϊk��������
��Map��¼ǰ׺�ͳ��ֵĴ�����
target = sum - k;

���target��map�г��ֹ���˵�� sum[i...j]��εĺ� Ϊk 
1 1 1 �� k = 2

sum = 0 1 2 3, k = 2
target = 0,-1,0,1
��ʼ��mp[0] = 1


0 1 2 3
	1-2 = -1 sum - k = target		++mp[sum]
	2-2 = 0  sum - k = target		++mp[sum] 
	3-1 = 0	 sum - k = target		++mp[sum]
	��¼ÿ��ǰ׺�ͳ����˶��ٴΣ�target��mp���ֹ�����֮ǰ�� sum = target �� ans += mp[sum]; ��++mp[sum] 
*/

class Solution {
public:
	//560. ��Ϊ K ��������	//930. ����ͬ�Ķ�Ԫ������
	/*
		nums[0...i....j]
		sum[0...i] - k == sum[0...j] - k, sum[i...j] = 0
		
		ϣ�� 
		preSumj - (preSumi - k) == k 
		�� 
		presum[j] - k == presum[i]-k
		
		�ڼ���presum[j]ʱ����Ҫ��¼�Ѿ���¼�˶��ٸ�presum[presum[j]-k] , ��presum[presum[i]-k] 
	*/ 
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mp{{0,1}};			//key��ǰ׺�ͣ� value��ǰ׺�ͳ��ֵĴ��� 
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
    
    //974. �Ϳɱ� K ������������
    // mod = presum[j]%k == presum[i]%k 
    /*
		���룺nums = [4,5,0,-2,-3,1], k = 5
		�����7 
	*/ 
    int subarraysDivByK(vector<int>& nums, int k) {
    	int n = 0, sum = 0;
		unordered_map<int,int> mp{{0,1}};			//key�������� value���������ֵĴ��� 
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
    
    //1590. ʹ������ܱ� P ����
    // ˼·�� ���ܺ� sum �� sum % p = mod;  ���mod != 0, �����������ҳ�һЩԪ����ɵ���������飬ʹ����͵���mod 
     int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        // ϸ�ڣ� accumulateʹ��0LL����
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

            //Ϊ�˱����ж� mod �Ƿ�Ϊ������target����д��
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
    
    //523 ������������� 
   	//presum[j] - presum[i]Ϊk�ı�������presum[j]%k == presum[i]%k  = mod
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = nums[0];
        unordered_map<int,int> mp{{sum%k,0}};       //key ������valueλ��

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
    
    // 525 �������� 
    //���ǿ��Խ������е� 0���� ?1����ԭ����ת���ɡ���������������飬��Ԫ�غ�Ϊ 0 
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int sum = 0, ans = 0;
        //ϸ��1 �涨�յ�ǰ׺�Ľ����±�Ϊ -1�� ���ڿյ�ǰ׺��Ԫ�غ�Ϊ 0
        
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
