

/*
思路1： bfs+优先级队列
	
	0 1 4
	2 8 7
	3 6 5

	贪心思路： 
		策略1： 
		每次周当前点周围最低的点 
					第一条路径：start->1->4->7->end
	 				第二条路径：start->2->3->6->end
	 	第一条路径对应的结果是 7，第二条路径对应的结果是 6
	 	
				   
	 	策略2： 所有的能走的点中我们永远只走水位最低的点 
	 		 	维护一个优先队列： 
				  	0, 1, 2
		 		   1,2,4,8
				   2,3,4,8 
				   3,4,6,8
				   4,6,7,8
				   6,7,8
				   找到邻居0,1,2,3,4,6 
				   选的点 
	
思路2： 二分答案 + bfs
	二分的对象是耗时
		不断的尝试能够走完的时间的上限limit
			若能 limit能够走完从起点到终点的路径，则减小limit
			否则增加limit
		最终,最小的limit即为满足条件的最少时间（即最优路径上最大的点） 
https://leetcode.cn/problems/swim-in-rising-water/
https://leetcode.cn/problems/swim-in-rising-water/solution/you-xian-dui-lie-fa-yi-ji-wei-he-hui-xiang-dao-you/	
*/ 

class Solution {
private:
    struct point {
        int x, y, d;
        point(){}
        point(int x,int y,int d):x(x),y(y),d(d){}
    };
    struct tmp2 {
        bool operator() (const point &a, const point &b) {
            return a.d > b.d;
        }
    };
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
	
	// 优先队列+bfs 
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<point,vector<point>,tmp2> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        q.push(point{0,0,grid[0][0]});
        visited[0][0] = true;

        int result = 0;

        while(!q.empty()) {
            point p = q.top();
            q.pop();
            result = max(result, p.d);
            if (p.x == m-1 and p.y == n-1) {
                break;
            }
            for (int *d : direction) {
                int dx = d[0] + p.x;
                int dy = d[1] + p.y;
                // cout << p.x << " " << p.y << " dx=" << dx << " dy=" << dy << endl;
                if ((dx>=0 && dx < m) && (dy>=0 && dy < n) && !visited[dx][dy]) {
                    visited[dx][dy] = true;
                    //因为在网格内部游泳时不耗时， 因此，到达dx, dy的代价是grid[dx][dy]
                    q.push(point{dx,dy,grid[dx][dy]});
                }
            }
        }
        return result;
    }
    
    // 二分 + bfs 
    int swimInWater(vector<vector<int>>& grid) {
        int left = -1, right = 3000;
        while (left + 1 < right) {
            int mid = left + (right-left) / 2;
            if (bfs(grid, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    bool bfs(vector<vector<int>>& grid, int mid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        if (mid < grid[0][0]) {
            return false;
        }
        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            for (int *d : direction) {
                int dx = d[0] + p.first;
                int dy = d[1] + p.second;
                if ((dx>=0 && dx < m) && (dy>=0 && dy < n) && !visited[dx][dy] && grid[dx][dy] <= mid) {
                    visited[dx][dy] = true;
                    q.push({dx,dy});
                }
            }
        }
        return visited[m-1][n-1];
    }
};

/*
0 1 4
2 8 7
3 6 5

q
0 1 2
1 2
2 4 8
3 4 8   //8会被反复push吗     
4 6 8
6 7 8


*/
