


//子集型回溯 

//78.子集
/*
给定一个数组，输出数组所有的子集 
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

分析： 子集，需要记录在递归路径上所有的path, 并将path加入结果集中 
*/ 
class Solution1 {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, path, 0);
        return ans;
    }

    void dfs(vector<int> &nums, vector<int> &path, int j) {
    	//下面这个if条件为什么可以不加？ 
         if (j > nums.size()) {
             return;
         }
         //纵向添加一个元素
        ans.push_back(path);

        //横向遍历多叉树
        for (int i = j; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, path, i+1);
            path.pop_back();
        }
    }
};


// 131. 分割回文串
/*
问题：给定一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

分析： 分割回文串，需要枚举每个满足条件的分割位置，用|分割， 满足条件的aab分割
								
								     aab
								     
							a|		aa|b		aab|
							
						a|a|b aa|b    aa|b
						
		问题2： 满足条件，只有当枚举出来的子字符串是回文串，才能开始枚举下一个子串
		判断子串是否是回文字符串， 用相向双指针法，或者把字符串反转过来 
*/ 

class Solution3 {
private:
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, path, 0);
        return ans;
    }

    void dfs(string &s, vector<string> &path, int j) {
        int n = s.size();
        if (j == n) {
            //每个字母都必须在答案中，因此，需要等到都分割完了，再加入结果集
            ans.push_back(path);
            return;
        }
        for (int i = j; i < n; i++) {
            string substr = s.substr(j,i-j+1);
            if (substr != string(substr.rbegin(), substr.rend())) {
                continue;
            }
            path.push_back(substr);
            dfs(s, path, i+1);
            path.pop_back();
        }
    }
};



////////////////////组合型回溯 ， 找到满足某一条件的路径组合 

//77. 组合
/*
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
思路：回溯， 用一个path数组记录路径上的数，当path.size() == 2 时， 加入到结果集
	从数字1开始递归，回溯终止条件： 遍历的下边 > n 
*/ 
class Solution {

private:
    vector<vector<int>>  ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(n, k, 1, path);
        return ans;
    }

    void dfs(int n, int k, int cur, vector<int> &path) {
        if (k == path.size()) {
            ans.push_back(vector<int>(path.begin(), path.end()));
            return;
        }
        if (cur > n) {
            return;
        }
        for (int i = cur; i <= n; i++) {
            path.push_back(i);
            dfs(n,k,i+1,path);
            path.pop_back();
        }

    }
};


//剑指 Offer II 104. 排列的数目
/*
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。

思路： 回溯 + 记忆化搜索，
	从target自顶往下搜索，当target <= 0时返回
	每次需要记录当前搜索的targte的方案数是多少，然后再递归返回的时候将组成当前层的target的方案数返回给上一层的数（target+nums[i]) 

	构建一棵递归树
										 4
									-1/  |-2 \-3 
								    3    2    1
							  -1/ -2| -3\ 
							   2    1   0
						-1/ -2| -3\ 
						1    0    -1
				  -1 /-2|-3\ 
				   0  -1  -2
				   
	剪枝：
		对nums进行升序排序， 当target - nums[i] < 0, 跳出循环，放弃枚举下一个数，因为nums[i] < nums[i+1]; target-nums[i+1] < target-nums[i] < 0  

	
	
	关于自顶向下，还是自底向上搜索
	自顶向下：dfs(n) -> dfs(n-1),  用于递归搜索， 当n == 0 时返回答案
	
	自底向上：dfs(i) -> dfs(i+1), 用于递推， 当 i==n 时， 递推结束，判断递推答案是否满足条件 
	自底向上方法是从小范围推大范围 
	
*/ 
class Solution {
private:
    int memo[1005];
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(memo, -1, sizeof(memo));
        dfs(nums, target);
        return memo[target];
    }
    int dfs(vector<int> &nums, int target) {
        if (target <= 0) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }
        if (memo[target] != -1) {
            return memo[target];
        }
        int n = nums.size();
        //初始化组成target的方案数为0
        memo[target] = 0;
        for (int i = 0; i < n; i++) {
            memo[target] += dfs(nums, target-nums[i]);
        }
        return memo[target];
    }
};


//回溯算法的时间复杂度 = sum (叶子节点数 * 叶子节点到根节点的路径长度） 
// 参考： https://www.bilibili.com/video/BV1xG4y1F7nC/?p=15&spm_id_from=pageDriver 
