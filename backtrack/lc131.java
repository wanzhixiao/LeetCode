package backtrack;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solusion131{
    List<List<String>> list = new ArrayList<>();
    boolean[][] dp;
    List<String> ans = new ArrayList<String>();

    public List<List<String>> partition(String s) {

        int n = s.length();
        dp = new boolean[n][n];

        for(int i=0;i<n;i++){   //全部fill成 true
            Arrays.fill(dp[i],true);
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] = (s.charAt(i)==s.charAt(j))&&dp[i+1][j-1];
            }
        }
        dfs(s,0);
        return list;
    }

    void dfs(String s, int i){
        if(i==s.length()){
            list.add(new ArrayList<String>(ans));
        }
        for(int j=i;j<s.length();j++){
            if(dp[i][j]){
                ans.add(s.substring(i,j+1));
                dfs(s,j+1);
                ans.remove(ans.size()-1);
            }
        }
    }
}

public class lc131 {
    public static void main(String[] args) {

        String s = "aab";
        Solusion131 solu = new Solusion131();

        List<List<String>> res = solu.partition(s);

//        for(List<String> list:res){
//            for(String str : list){
//                System.out.print(str+" ");
//            }
//            System.out.println();
//        }
    }

}
