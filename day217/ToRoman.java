package day217;

import java.util.HashMap;

public class ToRoman {
	 public static String intToRoman(int num) {	//整形转罗马
	        if(num<1||num>3999)
	            return null;
	        StringBuilder sbuilder=new StringBuilder();
	        int[] val = {1000,500,100,50,10,5,1};
	        String[] roman = {"M","D","C","L","X","V","I"};
	        for(int i=0;i<val.length;i++)
	        {
	            while(num>=val[i])
	            {
	                sbuilder.append(roman[i]);
	                num -= val[i];
	            }
	        }
	        
	        return sbuilder.toString();
	    }
	 
	    public static int romanToInt(String s) {	//罗马转整形
	        int[] val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	        String[] roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	        
	        HashMap<String,Integer> map = new HashMap<String,Integer>();
	        for(int i=0;i<val.length;i++)
	        {
	            map.put(roman[i],val[i]);
	        }
	        
	        int result=0;
	        for(int i=0;i<val.length;i++)
	        {
	           int index = s.indexOf(roman[i]);
	           if(index>0)
	           {
	               result += (Integer)map.get(roman[i]);
	           }
	            
	        }
	        return result;
	    }
	 
	 
	 public static void main(String[] args) {
		 int result = romanToInt("LVIII");
		 System.out.println(result);
//		 String string1="Hepllo";
//		 String string2 = "llo";
//		 int result = IndexOf(string1,string2);
//		 System.out.println(result);
		 
	}
	 
	 public static int IndexOf(String S,String T){
	        int i=0,j=0;
	        while(i<S.length() && j<T.length())
	        {
	            if(S.charAt(i)==T.charAt(j))
	            {
	                i++;
	                j++;
	            }
	            else
	            {
	              i = i-j+1;
	              j=0;
	            }
	        }
	        if(j>=T.length())
	            return i-T.length();
	        return -1;
	    }
	 
}
