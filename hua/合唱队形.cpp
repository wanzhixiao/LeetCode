#include <iostream>
#include <vector>
using namespace std;

int numOut(vector<int> nums, int n) {
    vector<int> dp1(n,1), dp2(n,1);
    dp1[n-1] = 0;
    for (int i = 1; i < n; i++) {
        int t_max = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                t_max = max(t_max, dp1[j]+1);
            }
        }
        dp1[i] = t_max;
    }
    dp2[n-1] = 0;
    for (int i = n-2; i >=0; i--) {
        int tmax = 1;
        for (int j = n-1; j > i; j--) {
            if (nums[i] > nums[j]) {
                tmax = max(tmax, dp2[j]+1);
            }
        }
        dp2[i] = tmax;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int t = dp1[i]+dp2[i]-1;
        ans = max(ans, t);
    }
    return n-ans;
}

int main() {
    int n;
    vector<int> nums;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }
    int ans = numOut(nums,n);
    cout << ans << endl;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
