#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
最大的矩形面积
    思路1：暴力法
        （1）枚举元素i
        （2）向左向右遍历所有元素，找到第一个小于height[i]的元素作为边界
        （3）ans = max(ans,(right-left+1)*height[i])
    思路2：单调栈
        使用单调栈保留每个元素 左侧
*/

int largestRectangleArea(vector<int>& heights) { 
    int n = heights.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        int j=i,k=i;
        int h = heights[i];
        for(;j>=1;j--){
            if(heights[j-1] < h){
                break;
            }
        }
        for(;k<n-1;k++){
            if(heights[k+1] < h){
                break;
            }
        }

        int area = (k-j+1)*h;
        ans = max(ans,area);

    }
    return ans;
}

int largestRectangleArea2(vector<int>& heights) { 
    int ans = 0;
    int n = heights.size();
    vector<int> rightStack(n,n);         //存储右边第一个比元素i小的元素
    vector<int> leftStack(n,0);          //存储左边第一个比元素i小的元素

    for(int i=0; i<n; i++){
        while(!rightStack.empty() && (rightStack.top()<height[i])){

        }
    }

    return ans;
}
int main(){
    vector<int> nums = {2,1,5,6,2,3};
    cout << largestRectangleArea(nums) << endl;
    return 0;
}