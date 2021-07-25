package day217;

/*
 * 最长回文子串
 * */


class Solution {
    public String longestPalindrome(String s) {
    	if(s.length()<=1)
    		return s;
    	int count=0;
    	String substr;
    	for(int i=s.length();i>0;i--)		//字符串长度
    	{
    		for(int j=0;j<=s.length()-i;j++)
    		{
    			count=0;
    			substr = s.substring(j,i+j);
    			for(int k=0;k<substr.length()/2;k++)
    			{
    				if(substr.charAt(k)==substr.charAt(substr.length()-k-1))
    					count++;
    			}
    			if(count==(substr.length()/2))
        			return substr;
    		}
    	}
    	
    	return "";
    }
}
public class LongHuiwen {
	public static void main(String[] args) {
		String str = "111bb";
		Solution s = new Solution();
		System.out.println(s.longestPalindrome(str));
	}
}
