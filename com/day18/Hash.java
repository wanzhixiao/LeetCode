package com.day18;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Hash {
	public static void main(String[] args) {
		
		String s = "qywyer23tdd";
		char ch = findFirstRepeat(s,s.length());
		
		System.out.println(ch);
	}
	
	public static char findFirstRepeat(String A, int n) {
		char ch=' ';
		Set<Character> set = new HashSet<Character>();
		for(int i=0;i<n;i++)
		{
			ch = A.charAt(i);
			if(!set.contains(ch))
				set.add(ch);
			else 
			{
				break;
			}
		}
		
		return ch;
    }
	
	public char findFirstRepeat2(String A, int n) {
        // write code here
         int[] flag = new int[256];
         Arrays.fill(flag, 0);
         int ascii = 0;
        char dc = ' ';
        for(int i=0; i<n; i++){

            char c = A.charAt(i);
            ascii = (int)c;
            flag[ascii] = flag[ascii] + 1;
            if(flag[ascii] > 1){
                dc = c;
                break;
            }

        }

        return dc;
    }
}
