package com.xiaohongshu;

import java.io.*;
import java.util.*;

public class TestInput
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int num;
        ArrayList<Integer> nums = new ArrayList<>();
        while(cin.hasNextInt())
        {

            num = cin.nextInt();
            nums.add(num);
        }

        //Comparator比较的是容器内的对象,o1-o2是升序， o1-o2<0?1:-1是降序
        nums.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1-o2<0?1:-1;
            }
        });
        for(Integer a:nums){
            System.out.print(a+" ");
        }
        System.out.println();
        cin.close();
    }
}