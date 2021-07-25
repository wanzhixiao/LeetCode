package com.day18;

public class MyTest {
	public char findFirstRepeat(String A, int n) {
	       if(n==0)
	           return ' ';
	        if(n==1)
	            return A.charAt(0);
	       for(int i=0;i<n;i++)
	       {
	           char ch = A.charAt(i);
	           for(int j=i+1;j<A.length();j++)
	           {
	               char h = A.charAt(j);
	                   if(ch==h)
	                       return ch;
	           }
	       }
	        return ' ';
	    }
}
