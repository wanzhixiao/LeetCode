#include<iostream>
#include<vector>
#include<unordered_map> 
using namespace std; 

/*
��Ϊk��������
nums = [-1,-1,1,-1,1], k = 0 

˼·1����������
	������ڸ������ظ������������ڲ����ã�ԭ���Ǵ����ڵ������и������������������ڵĺ� sum < k ʱ�� �����ƶ�left����right����ȷ��
	
	-1,-2,-1,-2,-1 
	
	ͬ�򻬶����ڣ���ָ�����ƺ���ָ�����Ƶ�Ч���෴ 
	
	
˼·2��
	ǰ׺�� + ��ϣ��
	�жϵ�ǰ ǰ׺�� presum[i] - k �ڹ�ϣ���г����˶��ٴΣ� ����һ��˵�� presum[i]�� presum[j]�ȼۡ�
	presum[j]-presum[i] = 0 , nums[i...j]֮��Ϊ0 
*/ 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int ans = 0;
        int left = 0, right = 0;
        int sum = 0;
        while(right < n) {
            sum += nums[right];

            while((left <= right) && (sum >= k)) {
                if(sum == k) {
                    ans++;
                }
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return ans;
    }
    
    int subarraySum2(vector<int>& nums, int k) {
    	int n = nums.size();
    	vector<int> presum(n+1,0);
		for(int i = 1; i <= n; i++) {
			presum[i] = presum[i-1] + nums[i-1];
		} 
		unordered_map<int,int> m{{0,1}};		//��1������ǰ׺�� Ϊ0,����Ϊ1 
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int tar = presum[i] - k;
			if (m.count(tar)) {
				ans = ans + m[tar];
			}
			++m[presum[i]];
		} 
		return ans;
    } 
    
};

int main() {
	vector<int> nums = {-1,-1,1,-1,1};
	int k = 0;
	Solution s;
	cout << s.subarraySum2(nums,k) << endl;
	return 0;
}
