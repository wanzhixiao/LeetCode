class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (vector<int> e:edges) {
            int v1 = e[0], v2 = e[1];
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        
        vector<int> pa(price.begin(), price.end()),pb(price.begin(), price.end());
        
        function<void(int)> bfs = [&](int start) {
            queue<int> q;
            vector<bool> vis(n,false);
            vis[start] = true;
            q.push(start);
            int depth = 0;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int node = q.front();
                    q.pop();
                    
                    if (depth%2 == 0) {
                        pa[node] /= 2;
                    } else {
                        pb[node] /= 2;
                    }
                    
                    for (int x : g[node]) {
                        if (!vis[x]) {
                            vis[x] = true;
                            q.push(x);
                        }
                    }
                }
                depth++;
            }
        };
        
        function<int(int,int,bool)> bfs2 = [&](int start, int end,bool isOld) {
            queue<pair<int,int>> q;
            vector<bool> vis(n,false);
            vis[start] = true;
            q.push({start,isOld ? pa[start] : pb[start]});
            
            while (!q.empty()) {
                pair<int,int> p = q.front();
                q.pop();
                int node = p.first, cost = p.second;
                if (node == end) {
                    return cost;
                }
                for (int x : g[node]) {
                    if (vis[x]) {
                        continue;
                    }
                    vis[x] = true;
                    q.push({x,cost + (isOld ? pa[x] : pb[x])});
                }
            }
            return -1;
        };
        
        bfs(0);
        
        for (int i = 0; i < n; i++) {
            cout << i << " " << pa[i] << " -- " << pb[i] << endl;
        }
        
        int ans = 0;
        for (vector<int> trip : trips) {
            int a1 = bfs2(trip[0], trip[1], true);
            int a2 = bfs2(trip[0], trip[1], false);
            ans = ans + min(a1,a2);
            cout << trip[0] << " " << trip[1] << " " << a1 << " " << a2 << " " << endl;
        }
        
        return ans;
    }
};
