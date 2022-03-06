#include<iostream>
#include<stack>
using namespace std;


class Solution {
public:
    /**
     * 
     * @param s string×Ö·û´® 
     * @return intÕûÐÍ
     */
    int longestValidParentheses(string s) {
        // write code here
        stack<int> stk;
        int n = s.size();
        stk.push(-1);
        int ans = 0;
        
        for(int i=0; i<n; i++){
        	char ch = s[i];
        	
			if(ch=='('){
				stk.push(i);
			} else{ //ch == ')' 
				 if(stk.size()>1){
				 	stk.pop();
//				 	cout << s[stk.top()] << " " << stk.top()<<endl;
					int last_not_match = stk.top();
					ans = ans > (i-last_not_match) ? ans : (i-last_not_match);
				} else{
					stk.pop();
					stk.push(i);
				}

			}
		}
        
        return ans; 
    }
};

int main(){
	
//	string s = ")()(()()((((((())(";
	string s = ")()(()()((((((())("; 
//	string s = "(())";
	Solution solu;
	cout << solu.longestValidParentheses(s) << endl;
	
	return 0;
} 
