package com.c360;

import java.util.*;

public class Main3601 {
    public static void main(String[] args) {
        int n,p,q;
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] numbers = line.split(" ");

        n = Integer.parseInt(numbers[0]);
        p = Integer.parseInt(numbers[1]);
        q = Integer.parseInt(numbers[2]);

        line = sc.nextLine();
        String[] numbers2 = line.split(" ");

        Integer[] scores = new Integer[n];
        for(int i=0;i<n;i++){
            scores[i] = Integer.parseInt(numbers2[i]);
        }

        Arrays.sort(scores, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return (o1-o2)<0?1:-1;
            }
        });

        int[] cnt = new int[101];
        for(int i=0;i<n;i++){
            cnt[scores[i]]++;
        }

        int normal_score = 100,res=0;
        for(int i=100;i>=0;i--){
            if(cnt[i] != 0){
                double finalscore = (double)(p*normal_score+q*i)/100;
                if(finalscore>=60.0){
                    res += cnt[i];
                }
                normal_score--;
            }
        }
        System.out.println(res);
    }
}
