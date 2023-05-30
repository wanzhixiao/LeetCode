

/*
˼·1�� bfs+���ȼ�����
	
	0 1 4
	2 8 7
	3 6 5

	̰��˼·�� 
		����1�� 
		ÿ���ܵ�ǰ����Χ��͵ĵ� 
					��һ��·����start->1->4->7->end
	 				�ڶ���·����start->2->3->6->end
	 	��һ��·����Ӧ�Ľ���� 7���ڶ���·����Ӧ�Ľ���� 6
	 	
				   
	 	����2�� ���е����ߵĵ���������Զֻ��ˮλ��͵ĵ� 
	 		 	ά��һ�����ȶ��У� 
				  	0, 1, 2
		 		   1,2,4,8
				   2,3,4,8 
				   3,4,6,8
				   4,6,7,8
				   6,7,8
				   �ҵ��ھ�0,1,2,3,4,6 
				   ѡ�ĵ� 
	
˼·2�� ���ִ� + bfs
	���ֵĶ����Ǻ�ʱ
		���ϵĳ����ܹ������ʱ�������limit
			���� limit�ܹ��������㵽�յ��·�������Сlimit
			��������limit
		����,��С��limit��Ϊ��������������ʱ�䣨������·�������ĵ㣩 
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
	
	// ���ȶ���+bfs 
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
                    //��Ϊ�������ڲ���Ӿʱ����ʱ�� ��ˣ�����dx, dy�Ĵ�����grid[dx][dy]
                    q.push(point{dx,dy,grid[dx][dy]});
                }
            }
        }
        return result;
    }
    
    // ���� + bfs 
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
3 4 8   //8�ᱻ����push��     
4 6 8
6 7 8


*/
