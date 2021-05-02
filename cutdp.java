package leetcode;

import java.util.Scanner;

class Solution {
    public int waysToStep(int n) {
        int arr[] = new int[n+1];

        if(n==1){
            return 1;
        }else if(n==2){
            return 2;
        }else if(n==3){
            return 4;
        }

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;

        int MOD = 1000000007;

        for(int i=4;i<=n;i++){
            arr[i] = arr[i-1]+arr[i-2];
            if(arr[i]>MOD){
                arr[i] = arr[i]%MOD;
            }
            arr[i] += arr[i-3];
            if(arr[i]>MOD){
                arr[i] = arr[i]%MOD;
            }

        }

        return arr[n];
    }
}

public class cutdp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution sl = new Solution();

        while(sc.hasNextInt()){
            int n = sc.nextInt();
            int result = sl.waysToStep(n);

            System.out.println(result);
        }
    }
}
