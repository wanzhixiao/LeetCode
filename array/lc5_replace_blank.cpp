#include<iostream>
#include<string>
using namespace std;

string replaceSpace(string &s) {
        int a = 0;
        int n1 = s.size();
        for(int i=0;i<n1;i++){
            if(s[i] == ' '){
                a++;
            }
        }
        s.resize(s.size()+2*a);
        string pattern = "%20";
        int n2 = s.size();
        int left = n1-1,right = n2-1;
        while(left<right){          //这里为什么是left<right而不是left>=0?
            while(s[left]!=' '){
                s[right] = s[left];
                right--;
                left--;
            }
            s[right] = '0';
            s[right-1] = '2';
            s[right-2] = '%';
            right-=3;
            left -= 1;

        }
        return s;
    }
}

int main(){

    string t = "We are happy.";
    cout << t.size() << endl;
    string result = replaceSpace(t);
    result.resize(result.size()+5);
    cout << t.size() <<" " << result.size() << endl;

    return 0;
}