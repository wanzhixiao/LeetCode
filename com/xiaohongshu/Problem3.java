package com.xiaohongshu;

import java.util.*;

public class Problem3 {

    public static int countMaxPeroid(ArrayList<ArrayList<String>> arr){
        //1. paser String
        ArrayList<ArrayList<Double>> timeList = new ArrayList<>();
        for (int i = 0; i < arr.size(); i++) {
            double start = parse(arr.get(i).get(0));
            double end = parse(arr.get(i).get(1));
            ArrayList<Double> time = new ArrayList<>();
            time.add(start);
            time.add(end);
            time.add(end-start);
            System.out.println(start+" "+end+" "+(end-start));

            timeList.add(time);
        }
        System.out.println(timeList);
        //2. sort by the begin and length of moive
        //Arrays.sot()用于对基础类型数组进行排序
        timeList.sort(new Comparator<ArrayList<Double>>() {
            @Override
            public int compare(ArrayList<Double> o1, ArrayList<Double> o2) {
                int res = 0;
                double a = (o1.get(0) - o2.get(0));
                if(a!=0){
                    res = a<0?-1:1;
                }else{
                    res = (o1.get(2) - o2.get(2))<0?1:-1;
                }
                return res;
            }
        });
        System.out.println(timeList);

        //greedy algorithm
        int j = 0,count = 1;
        boolean [] a = new boolean[timeList.size()];
        a[0] = true;
        for(int i=1;i<timeList.size();i++){
            if(timeList.get(i).get(0)>timeList.get(j).get(0)){
                j = i;
                a[i] = true;
                count++;
            }else{
                a[i] = false;
            }
        }

        return count;
    }

    public static Double parse(String str){
        Double hour = 0.0,minute = 0.0;
        String hh = str.split(":")[0];
        String mm = str.split(":")[1];

        for(char c : hh.toCharArray()){
            hour = ((int)c-48)+ hour*10;
        }
        for(char c : mm.toCharArray()){
            minute = ((int)c-48)+ minute*10;
        }
        return hour + minute/60;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<ArrayList<String>> strList = new ArrayList<>();
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            String start = sc.next();
            String end = sc.next();
            strList.add(new ArrayList<>(Arrays.asList(start,end)));
        }

        int res = countMaxPeroid(strList);
        System.out.println(res);
    }
}
