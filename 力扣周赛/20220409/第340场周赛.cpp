
//第一题
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int m = nums.size();
        vector<int> primes;
        for (int i = 0; i < m; i++) {
            primes.push_back(nums[i][i]);
        }
        for (int i = 0, j = m-1; i < m && j >= 0; i++,j--) {
            if (i==j){
                continue;
            }
            primes.push_back(nums[i][j]);
        }
        sort(primes.begin(), primes.end(),[](int a,int b){return a>b;});
        for (int x : primes) {
            if (x == 1) {
                continue;
            }
            bool flag = true;
            for (int i = 2; i*i <= x; i++) {
                if (x % i == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return x;
            }
        }
        return 0;
    }
}; 


//第二题
class Solution {
    int mod = 100000;
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> m;
        for(int i = 0; i < n; i++) {
            if (m.count(nums[i]) == 0) {
                m[nums[i]] = vector<int>{i};
            } else {
                m[nums[i]].push_back(i);
            }
        }
        vector<long long> ans(n,0);
        unordered_map<int,vector<int>>::iterator it = m.begin();
        while (it != m.end()){
            int val = it->first;
            vector<int> idx = it->second;
            ++it;
            if (idx.size() <= 1) {
                continue;
            }
            for (int i = 0; i < idx.size(); i++) {
                long long s = 0;
                for (int j = 0; j < idx.size(); j++) {
                    if (i == j) {
                        continue;
                    }
                    s = s + abs(idx[i]-idx[j]);
                }
                ans[idx[i]] = s;
            }

        }
        return ans;
    }
}; 

//第三题
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int left = -1, right = *max_element(nums.begin(),nums.end());
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (check(nums,p,mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
    bool check(vector<int> &nums, int p, int mid) {
        int cnt = 0;
        int diff = 0;
        int n = nums.size();
        vector<bool> used(n,false);
            
        for (int i = 1; i < nums.size(); i++) {
            if ((abs(nums[i]-nums[i-1]) <= mid) && (!used[i-1]&&!used[i])) {
                // cout << mid << " "<< i << " " << i-1 << endl;
                used[i] = true;
                used[i-1] = true;
                cnt++;
            }
            if (cnt == p) {
                return true;
            }
        }
        return false;
    }
}; 

// 第四题 
class Solution {

public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m,vector<int>(n,-1));
        q.push({0,0});
        dist[0][0] = 1;
        int ans = 1;
        while (!q.empty()) {
            auto p = q.front();
            int x = p.first, y = p.second;
            q.pop();
            if (x == m-1 && y == n-1) {
                return dist[x][y];
            }
            
            int my = min(grid[x][y] + y, n-1);
            int mx = min(grid[x][y] + x, m-1);
            
            //这两个循环太耗时了, 是否真的需要每个点都加入队列中？？
            // if (x == m-1 && my < n-1) {
            //     continue;
            // }
            // if (y == n-1 && mx < m-1) {
            //     continue;
            // }
            for (int i = x+1; i <= mx; i++) {
                if (dist[i][y] == -1) {
                    dist[i][y] = dist[x][y]+1;
                    q.push({i,y});
                }
            }
            for (int j = y+1; j <= my; j++) {
                if (dist[x][j] == -1) {
                    dist[x][j] = dist[x][y]+1;
                    q.push({x,j});
                }
            }  
        }
        return -1;
    }
};
