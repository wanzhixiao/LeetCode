package backtrack;


import java.util.ArrayList;
import java.util.List;

class Solution0807 {
    List<String> list = new ArrayList<>();
    public String[] permutation(String S) {
        StringBuffer sbuf = new StringBuffer();
        dfs(S,sbuf);
        return list.toArray(new String[list.size()]);
    }

    public void dfs(String s,StringBuffer sbuf ){
        if(sbuf.length() == s.length()){
            list.add(new String(sbuf));
            return;
        }

        for(int i= 0;i<s.length();i++){
            String sub = new String(sbuf);
            if(sub.contains(s.charAt(i)+"")){
                continue;
            }
            sbuf.append(s.charAt(i));
            dfs(s,sbuf);
            sbuf = sbuf.deleteCharAt(sbuf.length()-1);
        }
    }
}

public class lc0807 {
    public static void main(String[] args) {
        String s = "a  ";

        Solution0807 solu = new Solution0807();
        String[] res = solu.permutation(s);
        for(String ss: res){
            System.out.println(ss);
        }


//        String[] arr = new String[list.size()];
        //list.toArray(arr);

//        String[] arr = list.toArray(new String[0]);
//        for(int i=0;i<arr.length;i++){
//            System.out.println(arr[i]);
//        }
    }
}
