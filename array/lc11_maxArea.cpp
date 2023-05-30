#include<bits/stdc++.h>
using namespace std;

//暴力法，超时
int maxArea(vector<int>& height) {
    int n = height.size();
    int ans = 0,h = INT_MAX, area = 0;

    for(int i=0;i<n;i++){
        h = height[i];
        int tmp = 0;
        for(int j=i+1;j<n;j++){
            area = (j-i)*min(h,height[j]);
            tmp = tmp > area ? tmp : area;
        }
        ans = max(tmp,ans);
    }
    return ans;
}

//双指针法
//[1,8,6,2,5,4,8,3,7]
int maxArea(vector<int>& height) {
    int n = height.size();
    int ans = 0, area = 0;
    int left = 0, right = n-1;
    while(left < right){
        int h = height[left] < height[right] ? height[left] : height[right];
        area = (right-left)*h;
        ans = max(area,ans);
        if(height[left]<height[right]){             //哪侧小移动哪侧  
            left++;
        }else{
            right--;
        }
    }
    return ans;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}