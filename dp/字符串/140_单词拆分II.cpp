#include<iostream>
#include<vector>
using namespace std;


/*
140. ���ʲ�� II
�жϵ�ǰ�ָ�ĵ����Ƿ����ֵ��г��ֹ�������ǣ��򽫵��ʼ���path, ������һ��λ�õ�dfs
����û�г��ֹ������м�֦ 
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

/*131 �ָ���Ĵ�
�жϵ�ǰ�ָ�ĵ����Ƿ��ǻ��Ĵ�������ǣ��򽫵��ʼ���path, ������һ��λ�õ�dfs
���򣬲��ǻ��Ĵ������м�֦ 
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
        // Ϊ�˿����ж�һ�������Ƿ��ڵ��ʼ����У���Ҫ�����Ǽ����ϣ��
        Set<String> wordSet = new HashSet<>(wordDict);
        int len = s.length();

        // �� 1 ������̬�滮�����Ƿ��н�
        // dp[i] ��ʾ�����ȡ�Ϊ i �� s ǰ׺�Ӵ����Բ�ֳ� wordDict �еĵ���
        // ���Ȱ��� 0 �����״̬����ĳ���Ϊ len + 1
        boolean[] dp = new boolean[len + 1];
        // 0 ���ֵ��Ҫ�������״ֵ̬�ο������һ������������ wordDict �У�dp[0] ���ó� true �Ǻ����
        dp[0] = true;

        for (int right = 1; right <= len; right++) {
            // ������ʼ����еĵ��ʳ��ȶ��������Ӻ���ǰ�����Ǹ����
            for (int left = right - 1; left >= 0; left--) {
                // substring ����ȡ s[right]��dp[left] �Ľ�������� s[left]
                if (wordSet.contains(s.substring(left, right)) && dp[left]) {
                    dp[right] = true;
                    // ��� break ����Ҫ��һ���õ� dp[right] = True �������ټ�����ȥ
                    break;
                }
            }
        }

        // �� 2 ���������㷨�������з��������Ľ�
        List<String> res = new ArrayList<>();
        if (dp[len]) {
            Deque<String> path = new ArrayDeque<>();
            dfs(s, len, wordSet, dp, path, res);
            return res;
        }
        return res;
    }

    /**
     * s[0:len) ������Բ�ֳ� wordSet �еĵ��ʣ��ѵݹ����Ľ������ res ��
     *
     * @param s
     * @param len     ����Ϊ len �� s ��ǰ׺�Ӵ�
     * @param wordSet ���ʼ��ϣ��Ѿ������ϣ��
     * @param dp      Ԥ����õ��� dp ����
     * @param path    ��Ҷ�ӽ�㵽������·��
     * @param res     �������н���ı���
     */
    private void dfs(String s, int len, Set<String> wordSet, boolean[] dp, Deque<String> path, List<String> res) {
        if (len == 0) {
            res.add(String.join(" ",path));
            return;
        }

        // ���Բ�ֵ���߽�� len - 1 ����ö�ٵ� 0
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
