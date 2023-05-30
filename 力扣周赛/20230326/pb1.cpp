class Solution {
public:
    int kItemsWithMaximumSum(int numberOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        while (numberOnes > 0 && k > 0) {
            ans += 1;
            numberOnes--;
            k--;
        }
        while (numZeros > 0 && k > 0) {
            ans += 0;
            numZeros--;
            k--;
        }
        while (numNegOnes > 0 && k > 0) {
            ans -= 1;
            numNegOnes--;
            k--;
        }
        return ans;
    }
};
