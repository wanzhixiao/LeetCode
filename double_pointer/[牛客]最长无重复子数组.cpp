
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        int i = 0,ans=0;
        map<int,int> mMap;
        for(int j=0;j<arr.size();j++){
            if(mMap.find(arr[j])!=mMap.end()){
                i = max(i,mMap[arr[j]]+1);
            }
            ans = max(ans,j-i+1); 
        }
        return ans;
    }
};

int main(){
	vector<int> v = {3,3,2,1,3,3,3,1};
	Solution s;
	cout << s.maxLength(v) << endl;
}
/*
3,3,2,1,3,3,3,1

i = mMap[arr[j]]+1;
i=0 j=0 arr[j]=3 ans=1
i=1 j=1 arr[j]=3 ans=1
i=1 j=2 arr[j]=2 ans=2
i=1 j=3 arr[j]=1 ans=3
i=2 j=4 arr[j]=3 ans=3
i=5 j=5 arr[j]=3 ans=3
i=6 j=6 arr[j]=3 ans=3
i=4 j=7 arr[j]=1 ans=4

i = max(i,mMap[arr[j]]+1);
i=0 j=0 arr[j]=3 ans=1
i=1 j=1 arr[j]=3 ans=1
i=1 j=2 arr[j]=2 ans=2
i=1 j=3 arr[j]=1 ans=3
i=2 j=4 arr[j]=3 ans=3
i=5 j=5 arr[j]=3 ans=3
i=6 j=6 arr[j]=3 ans=3
i=6 j=7 arr[j]=1 ans=3






*/
