
/*
414 目标和：
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

思路1：回溯法，从0开始加和减， 递归达到target, 结果+1， 回溯返回的条件是树的深度（数组下标）为n时，不能继续遍历下一个数
	  返回条件：当前遍历的数的下标i == 数组长度n
	  子问题：dfs(nums, i+1, sum + nums[i], target) 和 dfs(nums, i+1, sum-nums[i], target)
	  注意: 需要所有所有数的参与，因此，需要i==n时，才能统计答案 
	  
	  使用down-top的方式画出递归搜索树
	  											0
											+1/ -1\
											1     -1
									    +1/-1\						
	                                    2    0
	                                +1/-1\
	                                3    1                   i=3, sum == target, 但是还没有完成所有数的搜索，走的是从根节点到叶子节点的路径 
	  						    +1/-1\		
	  							4    2	
	  		    			+1/-1\
	  						5	 3							i=5, sum == targte, 走到根节点，4-1=3， 满足条件； ans += 1;
							  
	问题1：求解的目标是否需要数组的所有元素的参与？
	是 ： 遍历完所有的数
	否： 用路径上的值求解
	
	问题2：搜索是top-down 还是 down-top ?  
	top-down: 原问题 dfs(n), 子问题dfs(n-1),  递归停止条件 n == 0
	down-top: 原问题 dfs(i), 子问题dfs(i+1),  递归停止条件 i == n 
	
	参考104题
	下一层可选的数是所有的数，还是当前层（下标）的下一个数？
	使用top-down的形式 
	104 题是可选所有数，即数字可以重复使用，每层往下一层遍历做选择都是，遍历一个长度为n的多叉树 
															4
													  -1/ -2| -3\
													   3   2	1
											     -1/ -2| -3\
												  2    1   0
											  -1/ -2\ -1|
											   1    0   0			 
	 
		
思路2： 记忆化搜索
	记录每个sum的组合个数，由于到达下标i时， 由于sum可正可负；  存的应该是 memo[i_sum] = value;  key为i_sum, 即下标_sum的对应的组合个数
	需要在每一层，搜索sum的组合种数
	 
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
	//方法1： 回溯法 
    int findTargetSumWays1(vector<int>& nums, int target) {
        dfs1(nums, 0, 0, target);
        return ans;
    }
    void dfs1(vector<int> &nums, int i , int sum, int target) {
        int n = nums.size();
        if (i == n) {
            //细节：需要所有元素都包括进来，如果+-所有元素的和==target, 则ans += 1;
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
	
	//方法2：记忆化搜索 
    int findTargetSumWays2(vector<int>& nums, int target) {
        return dfs2(nums, 0, 0, target);
    }
    
    int dfs2(vector<int> &nums, int i , int sum, int target) {
        string key = to_string(i) + "_" + to_string(sum);
        if (memo.find(key) != memo.end()) {          //sum 可能为-1,需要添加idx，  idx_sum
            return memo[key];
        }

        int n = nums.size();
        if (i == n) {
            //需要所有元素都包括进来，如果+-所有元素的和==target, 则ans += 1;
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
