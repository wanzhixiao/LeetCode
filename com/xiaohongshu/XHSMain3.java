package com.xiaohongshu;
import java.util.*;

//https://www.nowcoder.com/discuss/714911
public class XHSMain3 {
    static int res = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =Integer.parseInt(sc.nextLine());
        Film[] films = new Film[n];
        for (int i = 0; i < n; i++) {
            String s = sc.nextLine();
            String[] strs1=s.split("-");
            String[] start = strs1[0].split(":");
            String[] end = strs1[1].split(":");
            films[i] = new Film(Integer.parseInt(start[0])*60+Integer.parseInt(start[1]),
                    Integer.parseInt(end[0])*60+Integer.parseInt(end[1]));
            films[i].time=films[i].end-films[i].start;
        }
        Arrays.sort(films, new Comparator<Film>() {
            @Override
            public int compare(Film o1, Film o2) {
                if(o1.start!=o2.start)
                    return o1.start-o2.start;
                return o1.end-o2.end;
            }
        });
        backTrack(films,0,0,0,0);
        System.out.println(res);
    }

    private static void backTrack(Film[] films,int index,int end,int now,int count) {
        if(index==films.length){
            if(count==3)
                res = Math.max(res,now);
            return;
        }
        if(films[index].start>=end) {
            backTrack(films, index + 1, films[index].end, now + films[index].time, count + 1);
        }
        backTrack(films,index+1,end,now,count);
    }

    static class Film{
        int start;
        int end;
        int time;

        public Film(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public String toString() {
            return "Film{" +
                    "start=" + start +
                    ", end=" + end +
                    ", time=" + time +
                    '}';
        }
    }
}

