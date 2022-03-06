#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
     
    //测试用例通过7/10 [6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3] 83不通过 
    long long maxWater(vector<int>& arr) {
        // write code here
        long long ans = 0, tmp = 0;
        int left = 0, right = 0;
        
        int n = arr.size();
        if(n<=1){
        	return 0;
		}
		
		while(right < n){
			
			if(right > 0){
				if(arr[right] > arr[right-1]){
					
					if(arr[left] > arr[right]){
						ans = (right - left-1) * arr[right] - tmp;
					}else{
						ans = (right - left -1)*arr[left]-tmp;
					}
					
					if(arr[right] >= arr[left]){
						left = right;
						tmp = 0;
					}
					
				}else{
					tmp += arr[right];
				}
			}
			right++;
		}
        return ans;	//为什么是除以2 
    }
    
    
    long long maxWater1(vector<int>& arr) {
    	long long ans = 0; 
    	int n = arr.size();
    	//1.找最高的柱子的值及其下标
    	int highest = arr[0], index = 0;
    	for(int i=1; i<n; i++){
    		if(highest < arr[i]){
    			highest = arr[i];
				index = i; 
			}
		}
		//2.双指针求左侧盛水量
		int left = 0, right = 0;
		for(;right<index;right++){
			if(arr[left] > arr[right]){
				ans += arr[left] - arr[right];
			}else{//arr[left] <= arr[right]不能盛水 
				left = right;
			}
		}
		left = n-1;
		right = n-1;
		//3.双指针求右侧盛水量 
		for(;left>index;left--){
			if(arr[left]<arr[right]){
				ans += arr[right]-arr[left];
			}else{
				right = left;
			}
		}
		return ans;
    }
    
    //木桶短板理论 
    long long maxWater2(vector<int>& arr) {
    	long long ans = 0; 
    	int n = arr.size();
    	
    	int left = 0, right = n-1;
    	
	    while(left < right && arr[left]<=arr[left+1]){
			left++;
		}
		while(left < right && arr[right-1]>=arr[right]){
			right--;
		}

    	while(left < right){
			int left_val = arr[left];
			int right_val = arr[right];
			
			if(left_val<=right_val){
				while(left < right && left_val > arr[++left]){
					ans += left_val - arr[left];
				}
			}else{
				while(left < right && right_val > arr[--right]){
					ans += right_val - arr[right];
				}
			}
		}
		return ans;
    }
    
        long long maxWater3(vector<int>& arr) {
	    	long long ans = 0; 
	    	int n = arr.size();
	    	
	    	int left = 0, right = n-1;
			int minHeight=0,buckHeight=0;
	    	while(left < right){
				minHeight = min(arr[left],arr[right]);
				buckHeight = buckHeight < minHeight ? minHeight : buckHeight;
				
				ans += arr[left] >= arr[right] ? (buckHeight-arr[right--]):(buckHeight-arr[left++]);
			
			}
			return ans;
    }
    
    
};

int main(){
	vector<int> arr = {3,1,2,5,2,4};
	Solution s;
	
	long long ans = s.maxWater3(arr);
	
	cout << ans << endl; 
	
	return 0;
}
