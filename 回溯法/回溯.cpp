


//�Ӽ��ͻ��� 

//78.�Ӽ�
/*
����һ�����飬����������е��Ӽ� 
���룺nums = [1,2,3]
�����[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

������ �Ӽ�����Ҫ��¼�ڵݹ�·�������е�path, ����path���������� 
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
    	//�������if����Ϊʲô���Բ��ӣ� 
         if (j > nums.size()) {
             return;
         }
         //�������һ��Ԫ��
        ans.push_back(path);

        //������������
        for (int i = j; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, path, i+1);
            path.pop_back();
        }
    }
};


// 131. �ָ���Ĵ�
/*
���⣺����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����
���룺s = "aab"
�����[["a","a","b"],["aa","b"]]

������ �ָ���Ĵ�����Ҫö��ÿ�����������ķָ�λ�ã���|�ָ ����������aab�ָ�
								
								     aab
								     
							a|		aa|b		aab|
							
						a|a|b aa|b    aa|b
						
		����2�� ����������ֻ�е�ö�ٳ��������ַ����ǻ��Ĵ������ܿ�ʼö����һ���Ӵ�
		�ж��Ӵ��Ƿ��ǻ����ַ����� ������˫ָ�뷨�����߰��ַ�����ת���� 
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
            //ÿ����ĸ�������ڴ��У���ˣ���Ҫ�ȵ����ָ����ˣ��ټ�������
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



////////////////////����ͻ��� �� �ҵ�����ĳһ������·����� 

//77. ���
/*
���룺n = 4, k = 2
�����
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
˼·�����ݣ� ��һ��path�����¼·���ϵ�������path.size() == 2 ʱ�� ���뵽�����
	������1��ʼ�ݹ飬������ֹ������ �������±� > n 
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


//��ָ Offer II 104. ���е���Ŀ
/*
���룺nums = [1,2,3], target = 4
�����7
���ͣ�
���п��ܵ����Ϊ��
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
��ע�⣬˳��ͬ�����б�������ͬ����ϡ�

˼·�� ���� + ���仯������
	��target�Զ�������������target <= 0ʱ����
	ÿ����Ҫ��¼��ǰ������targte�ķ������Ƕ��٣�Ȼ���ٵݹ鷵�ص�ʱ����ɵ�ǰ���target�ķ��������ظ���һ�������target+nums[i]) 

	����һ�õݹ���
										 4
									-1/  |-2 \-3 
								    3    2    1
							  -1/ -2| -3\ 
							   2    1   0
						-1/ -2| -3\ 
						1    0    -1
				  -1 /-2|-3\ 
				   0  -1  -2
				   
	��֦��
		��nums������������ ��target - nums[i] < 0, ����ѭ��������ö����һ��������Ϊnums[i] < nums[i+1]; target-nums[i+1] < target-nums[i] < 0  

	
	
	�����Զ����£������Ե���������
	�Զ����£�dfs(n) -> dfs(n-1),  ���ڵݹ������� ��n == 0 ʱ���ش�
	
	�Ե����ϣ�dfs(i) -> dfs(i+1), ���ڵ��ƣ� �� i==n ʱ�� ���ƽ������жϵ��ƴ��Ƿ��������� 
	�Ե����Ϸ����Ǵ�С��Χ�ƴ�Χ 
	
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
        //��ʼ�����target�ķ�����Ϊ0
        memo[target] = 0;
        for (int i = 0; i < n; i++) {
            memo[target] += dfs(nums, target-nums[i]);
        }
        return memo[target];
    }
};


//�����㷨��ʱ�临�Ӷ� = sum (Ҷ�ӽڵ��� * Ҷ�ӽڵ㵽���ڵ��·�����ȣ� 
// �ο��� https://www.bilibili.com/video/BV1xG4y1F7nC/?p=15&spm_id_from=pageDriver 
