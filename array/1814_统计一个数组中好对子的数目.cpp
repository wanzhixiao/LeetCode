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
            //����������ô��⣿��
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
�ٷ�����������������
res = (res + h[i - j]) % MOD;
h[i - j]++;

1.����
nums[i]+reverse(nums[j]) == nums[j] + reverse(nums[i])
nums[i]-reverse(nums[i]) == nums[j]-reverse(nums[j])

2.hashmap
��f(i) = nums[i]-reverse(nums[i]) ��f(i)Ϊһ������
ÿ�α���ʱ�� ++f(i); ��һ��hashmap�� key = f(i) = nums[i]-reverse(nums[i]), value Ϊ0..i�У� nums[i]-reverse(nums[i])���ֵĴ���

3.���
ans = ans + hashmap[nums[i]-reverse(nums[i])]    //j����ת��Ϊi
++hashmap[nums[i]-reverse(nums[i])]             //��������±��key=nums[i]-reverse(nums[i])��value+1

4.��ֹ�������
ע�⣬ans����������������
mod = 1e9+7
ans = (ans + hashmap[nums[i]-reverse(nums[i])])%mod

*/

/*
��ͬ���͵���Ŀ��
560. ��Ϊ K ��������
523. ������������� 
2488. ͳ����λ��Ϊ K ��������
6932. ͳ�ƺ����������Ŀ


*/
