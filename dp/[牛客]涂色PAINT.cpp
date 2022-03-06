#include<bits/stdc++.h>
using namespace std;

int main(){
	    string s;
    cin >> s;
    
    int len = s.length();
    int dp[len][len];
    
    for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++) 
            dp[i][j] = 1e9;

    
    for(int i=len-1;i>=0;i--){
        for(int j=i;j<len;j++){
            if(i==j){
                dp[i][j] = 1;
            }
            else if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j] < dp[i][j-1] ?  dp[i+1][j] : dp[i][j-1];
            }else{
//                 dp[i][j] = dp[i+1][j]<dp[i][j-1] ? dp[i+1][j]+1 : dp[i][j-1]+1;
                
               for(int k=i;k<j;k++){
			   	 dp[i][j] = dp[i][j] < (dp[i][k]+dp[k+1][j]) ? dp[i][j] : (dp[i][k]+dp[k+1][j]);
			   } 
                
            }
        }
    }
    cout << dp[0][len-1] << endl;
    return 0;
}

/*
RGBGR
RRRRR-> RGGGR -> RGBGR

以下测试用例不通过：
CAACEBBABCBEBBCACAAEEBBAAEBAAEDCEEEBECAAEAECBCCDEB 
*/ 
