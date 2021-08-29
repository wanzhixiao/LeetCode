package jianzhioffer;
//编辑距离小于2
class Solution0105 {
    /*双指针*/
    public boolean oneEditAway(String first, String second) {
        int m = first.length(),n=second.length();
        if(m==0 || n==0){
            return (m+n)<=1;
        }
        if(Math.abs(m-n)>1){
            return false;
        }

        int i=0,j=0;
        boolean edit = false;
        while(i<m && j<n){

            if(first.charAt(i) == second.charAt(j)){
                i++;
                j++;
            }else{
                if(!edit){
                    if(first.length() == second.length()){
                        i++;j++;
                    }else if(first.length()<second.length()){
                        j++;
                    }else{
                        i++;
                    }
                    edit = true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}

public class offer0105 {
    public static void main(String[] args) {

    }
}
