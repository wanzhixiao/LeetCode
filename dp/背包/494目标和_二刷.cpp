
/*
414 Ŀ��ͣ�
���룺nums = [1,1,1,1,1], target = 3
�����5
���ͣ�һ���� 5 �ַ���������Ŀ���Ϊ 3 ��
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

˼·1�����ݷ�����0��ʼ�Ӻͼ��� �ݹ�ﵽtarget, ���+1�� ���ݷ��ص�������������ȣ������±꣩Ϊnʱ�����ܼ���������һ����
	  ������������ǰ�����������±�i == ���鳤��n
	  �����⣺dfs(nums, i+1, sum + nums[i], target) �� dfs(nums, i+1, sum-nums[i], target)
	  ע��: ��Ҫ�����������Ĳ��룬��ˣ���Ҫi==nʱ������ͳ�ƴ� 
	  
	  ʹ��down-top�ķ�ʽ�����ݹ�������
	  											0
											+1/ -1\
											1     -1
									    +1/-1\						
	                                    2    0
	                                +1/-1\
	                                3    1                   i=3, sum == target, ���ǻ�û��������������������ߵ��ǴӸ��ڵ㵽Ҷ�ӽڵ��·�� 
	  						    +1/-1\		
	  							4    2	
	  		    			+1/-1\
	  						5	 3							i=5, sum == targte, �ߵ����ڵ㣬4-1=3�� ���������� ans += 1;
							  
	����1������Ŀ���Ƿ���Ҫ���������Ԫ�صĲ��룿
	�� �� ���������е���
	�� ��·���ϵ�ֵ���
	
	����2��������top-down ���� down-top ?  
	top-down: ԭ���� dfs(n), ������dfs(n-1),  �ݹ�ֹͣ���� n == 0
	down-top: ԭ���� dfs(i), ������dfs(i+1),  �ݹ�ֹͣ���� i == n 
	
	�ο�104��
	��һ���ѡ���������е��������ǵ�ǰ�㣨�±꣩����һ������
	ʹ��top-down����ʽ 
	104 ���ǿ�ѡ�������������ֿ����ظ�ʹ�ã�ÿ������һ�������ѡ���ǣ�����һ������Ϊn�Ķ���� 
															4
													  -1/ -2| -3\
													   3   2	1
											     -1/ -2| -3\
												  2    1   0
											  -1/ -2\ -1|
											   1    0   0			 
	 
		
˼·2�� ���仯����
	��¼ÿ��sum����ϸ��������ڵ����±�iʱ�� ����sum�����ɸ���  ���Ӧ���� memo[i_sum] = value;  keyΪi_sum, ���±�_sum�Ķ�Ӧ����ϸ���
	��Ҫ��ÿһ�㣬����sum���������
	 
	 key = to_string(i)+"_"+to_string(sum); 
	 res = 0;
	 res += dfs(nums, i+1, sum+nums[i], target);
	 res += dfs(nums, i-1, sum-nums[i], target);
	 memo[key] = res;

	 return res; 
	 
*/ 

class Solution {
    int ans = 0;
    unordered_map<string, int> memo;
public:
	//����1�� ���ݷ� 
    int findTargetSumWays1(vector<int>& nums, int target) {
        dfs1(nums, 0, 0, target);
        return ans;
    }
    void dfs1(vector<int> &nums, int i , int sum, int target) {
        int n = nums.size();
        if (i == n) {
            //ϸ�ڣ���Ҫ����Ԫ�ض��������������+-����Ԫ�صĺ�==target, ��ans += 1;
            if (target == sum) {
                ans += 1;
                return;
            }
            return;
        }
        dfs1(nums, i+1,sum+nums[i], target);
        dfs1(nums, i+1,sum-nums[i], target);
        return;
    }
	
	//����2�����仯���� 
    int findTargetSumWays2(vector<int>& nums, int target) {
        return dfs2(nums, 0, 0, target);
    }
    
    int dfs2(vector<int> &nums, int i , int sum, int target) {
        string key = to_string(i) + "_" + to_string(sum);
        if (memo.find(key) != memo.end()) {          //sum ����Ϊ-1,��Ҫ���idx��  idx_sum
            return memo[key];
        }

        int n = nums.size();
        if (i == n) {
            //��Ҫ����Ԫ�ض��������������+-����Ԫ�صĺ�==target, ��ans += 1;
            if (target == sum) {
                // ans += 1;
                return 1;
            }
            return 0;
        }

        int res = 0;
        res += dfs2(nums, i+1,sum+nums[i], target);
        res += dfs2(nums, i+1,sum-nums[i], target);
        memo[key] = res;
        return res;;
    }
};
