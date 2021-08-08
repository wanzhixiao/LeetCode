package com.java;

import java.util.Arrays;
import java.util.Comparator;

public class sort_compare {
    public static void main(String[] args) {
        Integer[] a = {9,8,7,6,5,4,3,2,1};
        Arrays.sort(a,new MyComparator());

        for(Integer num : a){
            System.out.println(num);
        }
    }
}

class MyComparator implements Comparator<Integer>{

    @Override
    public int compare(Integer o1, Integer o2) {
        if(o1<o2){
            return -1;
        }else if(o1>o2){
            return 1;
        }else{
            return 0;
        }
    }
}

