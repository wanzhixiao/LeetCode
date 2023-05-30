class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            int x = parent[i];
            if (x != -1) {
                g[x].push_back(i);
                g[i].push_back(x);
                // cout << x << " -- "<< i << endl;
            }
        }
        vector<bool> vis(n,false);
        set<char> st = dfs(g, s, 0, n, vis);
        return st.size();
    }

     set<char> dfs(vector<vector<int>> &g, string s, int u, int n, vector<bool> &vis) {
        if (vis[u]) {
            return set<char>();
        }
        vis[u] = true;
        set<char> res;
        int mx = 0;
        // �ҵ����ĺ��ӽڵ�����ļ��ϣ����ϵ�ǰ�ļ��ϣ����Ϸ���
        for (int child : g[u]) {
            
            if (!vis[child]) {
                set<char> tmp = dfs(g, s, child, n, vis);

                if (tmp.size()>0 && tmp.count(s[u]) != 0) {
                    continue;
                }
				
				// ��ο����ж� ������ - root - �������Ƿ��н����� 
                if (tmp.size() > mx) {
                    mx = tmp.size();
                    res = tmp;
                }
            }
        }
        res.insert(s[u]);
        return res;
     }
};
