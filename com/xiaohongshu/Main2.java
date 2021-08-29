package com.xiaohongshu;

import java.util.ArrayList;
import java.util.Comparator;

/**
 * 要求：尽可能多的活动
 * 限制：同一时间参加一个；不能中途推出；时间限制0.~23.59
 * 输入：
 * [["10:00","12:00"],["03:00","11:30"],["11:30","14:00"]]
 */
public class Main2{

    public static int countMaxActivity(ArrayList<ArrayList<String>> timeSchedule) {
        // 0 解析字符串
        ArrayList<ArrayList<Double>> times = new ArrayList<>();
        for (int i = 0; i < timeSchedule.size(); i++) {
            double start = StrParseInt(timeSchedule.get(i).get(0));
            double end = StrParseInt(timeSchedule.get(i).get(1));
            ArrayList<Double> time = new ArrayList<>();
            time.add(start);
            time.add(end);
            times.add(time);
        }
        System.out.println(times);
        // 1 排序
        times.sort(new Comparator<ArrayList<Double>>() {
            @Override
            public int compare(ArrayList<Double> o1, ArrayList<Double> o2) {
                return (int) (o1.get(0) - o2.get(0));
            }
        });
        System.out.println(times);
        // 2 以贪心的思路，将最早结束的活动加入到集合中
        int count = 1, n = times.size(), j = 0; // 记录最大活动数，活动总数
        boolean[] a = new boolean[n]; // 记录是否添加
        for (int i = 1; i < n; i++) {
            if (times.get(i).get(0) >= times.get(j).get(1)) { // 第i个活动开始时间 超过 j活动的结束时间
                a[i] = true;
                j = i;
                count++;
            } else {
                a[i] = false;
            }
        }
        return count;
    }

    public static double StrParseInt(String str) {
        String hour = str.split(":")[0];
        String mini = str.split(":")[1];
        double h = 0.0, m = 0.0;
        for (char c : hour.toCharArray()) {
            h = ((int) c - 48) + h * 10;
        }
        for (char c : mini.toCharArray()) {
            m = ((int) c - 48) + m * 10;
        }
        return h + m / 60;
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<String>> timeList = new ArrayList<>();  //二维数组
        ArrayList<String> activity1 = new ArrayList<>();
        activity1.add("10:00");
        activity1.add("12:00");
        timeList.add(activity1);
        ArrayList<String> activity2 = new ArrayList<>();
        activity2.add("03:00");
        activity2.add("11:30");
        timeList.add(activity2);
        ArrayList<String> activity3 = new ArrayList<>();
        activity3.add("11:30");
        activity3.add("14:00");
        timeList.add(activity3);
        System.out.println(timeList);
        int res = countMaxActivity(timeList);
        System.out.println(res);
    }
}