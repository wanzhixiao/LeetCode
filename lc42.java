package leetcode;

import java.util.HashMap;
import java.util.Map;

/*
* 约瑟夫环问题
* */
class Solution42 {
    public int findTheWinner(int n, int k) {

        int num = n;    //  人的总数

        Map<Integer,Integer> map = new HashMap<>();

        for(int j=1;j<=num;j++){
            map.put(j,j);
        }

        int next = 1+k-1;           //下一个人

        while(num>1){
//            next = (next+k-1)%num;
//            next = (next+k-1)%n;


//            System.out.println(next);



            //把next至为0
            if(map.get(next)!=null){
                map.remove(next);
                System.out.println("remove:"+next);
            }

            if(map.size()==2){
                next = (next+2*k)%n;
            }else{
                next = (next+k)%n;
            }
            System.out.println("next:"+next);

            next = map.get(next);

//            if(map.get(next) != 0){
//                map.replace(next,0);
//                next = (next+1)%num;
//            }
            --num;
        }

        return next;
    }
}

public class lc42 {

    public static void main(String[] args) {
        int n = 5,k=2;
        Solution42 s = new Solution42();
        System.out.println(s.findTheWinner(n,k));

    }
}
