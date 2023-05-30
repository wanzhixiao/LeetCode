

class Solution {
    struct point {
        int x,y,d;
        point(int x,int y, int d) : x(x), y(y), d(d){}
    };
    struct tmp2{
        bool operator()(const point &a, const point &b) { return a.d < b.d;}
    };
    const int INF = 0x3f3f3f3f;
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 999999;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right-left)/2;
 
            if (check(heights, mid)) {
                // cout << mid << endl;
                ans = mid;
                right = mid - 1;
            } else {
                left = mid +  1;
            }
        }
        return ans;
    }
    bool check(vector<vector<int>>& heights, int mid) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;

        while (!q.empty()) {
            //取数
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            //遍历邻居, 找到目标节点d
            for (int *d : directions) {
                int dx = d[0] + x;
                int dy = d[1] + y;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                    // 更新目标点d的gap, 放回最小的gap
                    if (abs(heights[dx][dy]-heights[x][y]) <= mid && !visited[dx][dy]) {
                        //标记为被访问
                        visited[dx][dy] = true;
                        //只能入一次队列
                        q.push({dx,dy});
                    } 
                } 
            }
        }
        // cout <<  visited[m-1][n-1] << " " << mid << endl;
        return visited[m-1][n-1];
    }
};

/*
1 2 2
3 8 2
5 3 5

5->3->5->3->1
5->2->2->2->1


1 2 3
3 4 8
5 3 5

1 3 6
3 2 4
5 3 5

*/
