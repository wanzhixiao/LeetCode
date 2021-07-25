package day217;

class Solution2 {
	
    public String addBinary(String a, String b) {
    	String result = new String();
    	int i=a.length()-1;
    	int j=b.length()-1;
    	int oper1,oper2;
    	int carray=0;
    	while(i>=0 || j>=0)
    	{
    		oper1 = i>=0?a.charAt(i--)-'0':0;
    		oper2 = j>=0?b.charAt(j--)-'0':0;
    		int temp = carray+oper1+oper2;
    		result += Integer.toString(temp%2);
    		carray = temp/2;
    	}
    	return carray==1 ? "1"+result:result;
    }
    
    
}

public class BinaryAdd {
	public static void main(String[] args) {
		Solution2 s2 = new Solution2();
		String  result = s2.addBinary("1", "1011");
    	System.out.println(result);
    	
    	System.out.println(result.indexOf("01"));
	}
}
