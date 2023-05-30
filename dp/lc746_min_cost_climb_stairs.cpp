#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i=2;i<n; i++){
            cost[i] = (cost[i-1]<cost[i-2]) ? cost[i-1] + cost[i] : cost[i-2] + cost[i];
        }
        int ans = cost[n-1] < cost[n-2] ? cost[n-1] : cost[n-2];
        return ans;
    }
};

int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    Solution s;
    cout << s.minCostClimbingStairs(cost) << endl;
    
    return 0;
}