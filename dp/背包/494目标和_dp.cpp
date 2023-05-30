#include<iostream>
#include<vector>
using namespace std;


/*
˼·��
		
		step1 : ����ת�� 
		
		������Ԫ���Ϊsum, ��Ӹ��ŵ�Ԫ�غ�Ϊneg, ����������ŵ�Ԫ�غ�Ϊsum-neg,  �õ��ı��ʽ���Ϊ
		(sum - neg) - neg = pos - neg = sum - 2neg =  target;
		neg = (sum-target)/2;
		
		neg�����ǷǸ������� sum-target�ǷǸ�����
		����ʽ����������ת����������nums��ѡ����Ԫ�أ�ʹ����ЩԪ��֮�͵���neg, ����ѡȡԪ�صķ����� 	
		
		step2 : ��̬�滮���ⶨ�� 
		����dp[i][j] Ϊ	 ʹ��ǰi�����������j������
		
		dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];  // j >= nums[i]
		dp[i][j] = dp[i-1][j];						 // j < nums[i]
		
		��ʼ����
		dp[0][0] = 1;
		
		ö�٣�
		��01����������ȫ������һ����ֻ��ʹ��һ�� 
		for(int i = 0; i < n; i++) {
			for (int j = 0; j<=target; j++) {
			
		}
		
		���մ�
		���� dp[n][neg] 
		
		
	

	P : ����ǰ���+�����ֺͣ�N����ǰ���-�����ֺ�
	S : ���������е����ֺ� 
	1: P+N =  S
	2: P-N = target
	 1ʽ-2ʽ�ã�
	 2N = S - target;   N = (S-target)/2
	 
	 ��ΪN > 0�� ���� S-target > 0;
	 ���ң� N % 2 == 0,  ��N %2 == 1, ���� P+N != S;  ��Ϊ P=N , 2P=2N=S  
	 
	 ��������ѡһЩ����ʹ����Щ���ĺ͵���N 
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int diff = sum-target;
        //neg Ϊ��Ӹ��ŵ�Ԫ�صĺͣ� neg >= 0 
        //(sum-neg)-neg = target = sum-2neg;  neg = (sum-target)/2;
        // neg >= 0 ,����sum-target >=0;  ���� (sum-target)%2 == 0;  //һ��Ϊ����һ��Ϊ��  0 = pos - neg;  pos+neg = sum; 2*neg = sum - target
        if (diff < 0 || diff % 2 != 0) {        
            return 0;
        }
        int neg = diff/2;
        vector<vector<int>> dp(n+1,vector<int>(neg+1,0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= neg; j++) {
                if (j >= nums[i-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][neg];
    }
    
    int findTargetSumWays2(vector<int>& nums, int target) {
	    int n = nums.size();
	    int sum = 0;
	    for (int i = 0; i < n; i++) {
	        sum += nums[i];
	    }
	    int diff = sum-target;
	    //(sum-neg)-neg = target = sum-2neg;  neg = (sum-target)/2;
	    // neg >= 0 ,����sum-target >=0;  ���� (sum-target)%2 == 0;  //һ��Ϊ����һ��Ϊ��  0 = pos - neg;  pos+neg = sum; 2*neg = sum - target
	    if (diff < 0 || diff % 2 != 0) {        
	        return 0;
	    }
	    int neg = diff/2;
	    vector<int> dp(neg+1,0);
	    dp[0] = 1;
	    for (int i = 1; i <= n; i++) {						
	        for (int j = neg; j >= nums[i-1]; j--) {
	        	//   1 1 1 1
	        	//   0 0 1 1      dp[2] = dp[2] + dp[2-1];  dp[1]��û�б����� 
	            dp[j] = dp[j] + dp[j-nums[i-1]];
	        }
	    }
	    return dp[neg];
	}
};

int main() {
	Solution solu;
	vector<int> nums = {1,1,1,1,1};
	int target = 3;
	
	cout << solu.findTargetSumWays2(nums, target) << endl;
	return 0;
} 
