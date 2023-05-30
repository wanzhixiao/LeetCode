

class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
		
		//需要用引用 
        sort(ranges.begin(), ranges.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0];});
        vector<vector<int>> ans;

        ans.push_back(ranges[0]);
        int ret = 2;
        for (int i = 1; i < n; i++) {
            if (ans.back()[1] >= ranges[i][0]) {
                int r = max(ans.back()[1], ranges[i][1]);
                ans.back()[1] = r;
            } else {
                ans.push_back(ranges[i]);
                ret = (ret << 1) % mod;
            }

        }
        return ret;
    }

    int countWays2(vector<vector<int>>& ranges) {
        int n = ranges.size();
        //用引用排序速度更快
        sort(ranges.begin(), ranges.end(), [](vector<int> &a, vector<int> &b) {return a[0] < b[0];});
        
        int r = ranges[0][1];
        int ret = 2;
        for (int i = 1; i < n; i++) {
            if (ranges[i][0] > r) {
                ret = (ret << 1) % mod;
            }
            r = max(r, ranges[i][1]);
        }
        return ret;
    }
    
};
