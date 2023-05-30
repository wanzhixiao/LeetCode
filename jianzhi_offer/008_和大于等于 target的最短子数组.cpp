#include<iostream>
#include<vector>
using namespace std;

/*
�ʹ��ڵ���target����������� 
target = 7, nums = [2,3,1,2,4,3]
���2 
���ͣ�������[4,3]�����������ĳ������������

˼·1��������
	ö�����������飬�ڱ��������н���������ͣ����������к͵�һ�δ���target������ѭ�� 
˼·2�� �������� 
˼·3��ǰ׺��+���ֲ��� 
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int tmp = INT_MAX;
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum >= target){
                    tmp = j-i+1;
                    break;
                }
            }
            ans = ans < tmp ? ans : tmp;
        }
        return ans==INT_MAX ? 0 : ans;
    }
    
    int minSubArrayLen2(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0, right = 0, minlen = INT_MAX;
        int sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                minlen = minlen < (right-left+1) ? minlen : (right-left+1);
                sum -= nums[left];
                left++;
            }
            ans = ans < minlen ? ans : minlen;
            right ++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
    
    int minSubArrayLen3(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> presum(n,0);
        presum[0] = nums[0];
        cout << presum[0] << " ";
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1] + nums[i];
            cout << presum[i] << " ";
        }
        cout << endl;
        for(int i=0;i<n;i++){
            int num = presum[i] - target;
            int left = -1, right = n;
            while(left + 1 != right){
				int mid = left + (right-left)/2;
				if(presum[mid]<=num){
					left = mid;
				} 
				else
				{
					right = mid;
				}
            }
            if(left != -1)
			{
				ans = ans < (i-left) ? ans : (i-left);
            
			}
			cout << num << " " << i << " " << left << endl;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};

int main()
{
	vector<int> nums={2,3,1,1,1,1,1};
	int target = 5;
	Solution s;
	cout << s.minSubArrayLen3(target,nums) << endl;
	return 0;
}
