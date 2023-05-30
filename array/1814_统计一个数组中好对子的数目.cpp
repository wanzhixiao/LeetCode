#include<iostream>
#include<string>
#include<string.h>
#include<vector> 
#include<unordered_map>
#include<cmath>
using namespace std; 

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> reversed;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = reverse(nums[i]);
            reversed.push_back(x);
        }
        int left = 0, right = n-1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (reversed[i] + nums[j] == nums[i] + reversed[j]) {
                    ans = ans + 1;
                }
            }
        }
        return ans;
    }
    
    int countNicePairs2(vector<int>& nums) {
        vector<int> reversed;
        int n = nums.size();
        int ans = 0;
        int mod = 1e9+7;
        vector<int> vec;
        unordered_map<int,int> cnt;
        for (int i = 0; i < n; i++) {
            int x = reverse(nums[i]);
            //下面两步怎么理解？？
            ans = (ans + cnt[nums[i]-x])%mod;
            ++cnt[nums[i]-x];
        }     

        return ans;
    }

    int reverse(int x) {
        long long ans=0;
        int z = abs(x);
        while (z>0) {
            int a = z%10;
            ans = ans*10 + a;
            z = z/10;
        }

        if (ans > pow(2,31)-1 || ans < -pow(2,31)) {
            return 0;
        }
        return x < 0 ? -ans : ans;
    }
};

int main() {
	
	return 0;
}

/*
官方题解中这两步的理解
res = (res + h[i - j]) % MOD;
h[i - j]++;

1.移项
nums[i]+reverse(nums[j]) == nums[j] + reverse(nums[i])
nums[i]-reverse(nums[i]) == nums[j]-reverse(nums[j])

2.hashmap
令f(i) = nums[i]-reverse(nums[i]) ，f(i)为一个常数
每次遍历时， ++f(i); 用一个hashmap存 key = f(i) = nums[i]-reverse(nums[i]), value 为0..i中， nums[i]-reverse(nums[i])出现的次数

3.求解
ans = ans + hashmap[nums[i]-reverse(nums[i])]    //j可以转化为i
++hashmap[nums[i]-reverse(nums[i])]             //遍历完该下标后，key=nums[i]-reverse(nums[i])的value+1

4.防止整数溢出
注意，ans可能整数溢出，因此
mod = 1e9+7
ans = (ans + hashmap[nums[i]-reverse(nums[i])])%mod

*/

/*
相同类型的题目：
560. 和为 K 的子数组
523. 连续的子数组和 
2488. 统计中位数为 K 的子数组
6932. 统计好子数组的数目


*/
