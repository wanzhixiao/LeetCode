#include<iostream>
#include<vector>
using namespace std;


/*
140. 单词拆分 II
判断当前分割的单词是否在字典中出现过，如果是，则将单词加入path, 继续下一个位置的dfs
否则，没有出现过，进行剪枝 
*/ 

class Solution {
private:
    unordered_set<string> st;
    vector<string> ans;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        dfs(s, 0, "");

        return ans;
    }

    void dfs(string &s, int j, string path){
        if (j == s.length()) {
            ans.push_back(path);
            return;
        }
        for (int i = j; i < s.length(); i++) {
            string substr = s.substr(j, i-j+1);
            if (st.find(substr) != st.end()) {
                dfs(s, i+1, !path.empty() ? path + " " +substr : substr);
            }
        }
    }
};

/*131 分割回文串
判断当前分割的单词是否是回文串，如果是，则将单词加入path, 继续下一个位置的dfs
否则，不是回文串，进行剪枝 
*/
class Solution2 {
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


public class Solution {

    public List<String> wordBreak(String s, List<String> wordDict) {
        // 为了快速判断一个单词是否在单词集合中，需要将它们加入哈希表
        Set<String> wordSet = new HashSet<>(wordDict);
        int len = s.length();

        // 第 1 步：动态规划计算是否有解
        // dp[i] 表示「长度」为 i 的 s 前缀子串可以拆分成 wordDict 中的单词
        // 长度包括 0 ，因此状态数组的长度为 len + 1
        boolean[] dp = new boolean[len + 1];
        // 0 这个值需要被后面的状态值参考，如果一个单词正好在 wordDict 中，dp[0] 设置成 true 是合理的
        dp[0] = true;

        for (int right = 1; right <= len; right++) {
            // 如果单词集合中的单词长度都不长，从后向前遍历是更快的
            for (int left = right - 1; left >= 0; left--) {
                // substring 不截取 s[right]，dp[left] 的结果不包含 s[left]
                if (wordSet.contains(s.substring(left, right)) && dp[left]) {
                    dp[right] = true;
                    // 这个 break 很重要，一旦得到 dp[right] = True ，不必再计算下去
                    break;
                }
            }
        }

        // 第 2 步：回溯算法搜索所有符合条件的解
        List<String> res = new ArrayList<>();
        if (dp[len]) {
            Deque<String> path = new ArrayDeque<>();
            dfs(s, len, wordSet, dp, path, res);
            return res;
        }
        return res;
    }

    /**
     * s[0:len) 如果可以拆分成 wordSet 中的单词，把递归求解的结果加入 res 中
     *
     * @param s
     * @param len     长度为 len 的 s 的前缀子串
     * @param wordSet 单词集合，已经加入哈希表
     * @param dp      预处理得到的 dp 数组
     * @param path    从叶子结点到根结点的路径
     * @param res     保存所有结果的变量
     */
    private void dfs(String s, int len, Set<String> wordSet, boolean[] dp, Deque<String> path, List<String> res) {
        if (len == 0) {
            res.add(String.join(" ",path));
            return;
        }

        // 可以拆分的左边界从 len - 1 依次枚举到 0
        for (int i = len - 1; i >= 0; i--) {
            String suffix = s.substring(i, len);
            if (wordSet.contains(suffix) && dp[i]) {
                path.addFirst(suffix);
                dfs(s, i, wordSet, dp, path, res);
                path.removeFirst();
            }
        }
    }
}

// https://leetcode.cn/problems/word-break-ii/solution/dong-tai-gui-hua-hui-su-qiu-jie-ju-ti-zhi-python-d/


int main() {
	
	return 0;
}
