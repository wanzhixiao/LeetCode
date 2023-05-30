#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
public:
	string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        if(n<m){
            a = string(m-n,'0')+a;
            n = m;
        }else if(n>m){
            b = string(n-m,'0')+b;
        }
        string ans = "";
        int carry = 0,pre=0;
        for(int i=n-1;i>=0;i--)
		{
            carry = (a[i] ^ b[i]) ? 0 : ((a[i]=='1') ? 1 : 0);
            if(carry == 0)
			{
                int num = ((a[i]-'0')+(b[i]-'0'));
                if(pre==0)
				{
                    ans = ans + to_string(num);
                }
                else
                {
                    if(pre + num > 1)
					{
                        ans = ans + '0';
                        carry = 1;
                    }
                    else
                    {
                        ans = ans + to_string(pre+num);
                    }
                }
            }
            else
            {//a[i] = '1' && b[i] == '1'
                if(pre == 1)
                    ans = ans + '1';
                else
                    ans = ans + '0';
            }   
            pre = carry;
        }
        if(carry==1)
		{
            ans = ans + '1';
        }
        return string(ans.rbegin(),ans.rend());
    }
};

int main(){
	
	return 0;
}
