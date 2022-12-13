#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;

/*

fruits = [1,2,3,2,2], output = 4; [2,3,2,2]
思路1：暴力解法
    枚举数组的每个子区间，判断其水果的种类的数量是否超过2，并取水果种类数不超过2的最长的子数组长度
    通过（70 / 91）超时



思路2：滑动窗口
采哪个子区间的水果
区间：代表能采集的树的子数组
起始位置：
结束位置：
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int result = 0;
        for(int i=0;i<n;i++){
            //该区间内水果的种类
            set<int> s;
            int sub_length = 0;
            for(int j=i;j<n;j++){
                if(s.find(fruits[j]) == s.end() && s.size() == 2){
                    break;
                }
                s.insert(fruits[j]);
                sub_length = j-i+1;
                result = result > sub_length ? result : sub_length;
            }
        }
        return result;
    }

    int totalFruit2(vector<int>& fruits) {
        int n = fruits.size();

        int cnt[n+10];
        int left = 0, ans = 0;
        for (int right = 0; right < n; ++right) {
            ++cnt[fruits[right]];
            while (cnt.size() > 2) {
                unordered_map<int, int>::iterator it = cnt.find(fruits[left]);
                --it->second;
                if (it->second == 0) {
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
    


    //窗口中的内容是什么，可以采摘的水果，种类不能超过2
    //右指针进行遍历
    //1.判断种类数是否大于2
    //2.当右指针遍历时，窗口内的数的种类数超过2，使左指针的数减少1个，同时左指针加1
    //3.如果左指针的数为0，去除这个种类
    //重复步骤1,2,3
    int totalFruit(vector<int>& fruits){
        int n = fruits.size();
        int cnt[n+10];
        for(int i=0; i<n;i++){
            cnt[fruits[i]] = 0;
        }
        int tot = 0, ans = 0;
        int l = 0, r = 0;
        while(r < n){
            if(++cnt[fruits[r]] == 1){
                tot += 1;
            }
            while(tot>2){
                --cnt[fruits[l]];
                if(cnt[fruits[l]]==0){
                    --tot;
                }
                l++;
            }
            ans = max(ans,(r-l+1));
            r++;
        }
        return ans;
    }

};

int main(){
    int arr[] = {3,3,3,1,2,1,1,2,3,3,4};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));

    Solution s;
    cout << s.totalFruit2(nums) << endl;

    return 0;
}