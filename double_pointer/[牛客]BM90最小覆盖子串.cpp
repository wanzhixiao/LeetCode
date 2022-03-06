#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param S string×Ö·û´® 
     * @param T string×Ö·û´® 
     * @return string×Ö·û´®
     */
    string minWindow(string S, string T) {
        // write code here
        int len1 = S.length(), len2 = T.length();
        if(len1 < len2){
            return "";
        }
        map<char,int> cMap;
        unordered_map <char, int> ori;//t×Ö·ûµÄÊýÁ¿
        for(int i=0;i<len1;i++){
            ori[T[i]]++;
        }
        string ans = "";
        int left = 0, right = 0;
        int minlen = 65535;
        while(right < len1){
//              cMap[S[right]]+=1;
            
            if(ori.find(S[right]) != ori.end()){
                cMap[S[right]]++;
            }
            
             if(right-left>=len2){
                 if(judge(T,ori) && (right-left+1) < minlen){
                     ans = S.substr(left,right-left+1);
                     minlen = right-left+1;
                 }
                 if(ori.find(S[left]) != ori.end()){
                     cMap[left]--;
                 }
                 left = left + 1;
             }else{
                right++;
             }
        }
        return ans;
    }
    
    bool judge(string &T,unordered_map<char,int> ori){
        for(int i=0; i<T.length();i++){
            if(ori[T[i]]-->0){
                 continue;
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
	string S,T;
	cin >> S >> T;
	Solution s;
	cout << s.minWindow(S,T) << endl;
	return 0;
}
