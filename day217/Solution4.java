package day217;

import java.util.Stack;

public class Solution4 {
	public static int longestValidStr(String s)
	{
		int res1 = 0;		//记录第一次匹配长度
		int res2 = 0;		//记录第二次匹配长度
		int res = 0;
		Stack<Character> stacka = new Stack<Character>();
		Stack<Character> stackb = new Stack<Character>();
		
		if(s.length()<2)
			return res1;
		

			for(int j=0;j<s.length();j++)
			{
				stacka.push(s.charAt(j));		//所有的字符入栈
			}
			
			while(!stacka.empty())
			{
				Character ch1 = stacka.pop();		//取栈a的元素与栈b的元素比较，如匹配，则b出栈，否则该元素进b栈
				if(!stackb.empty())
				{
					Character ch2 = stackb.peek();
					if(ch1=='<' && ch2=='>')
					{
						stackb.pop();
						res1+=2;						//匹配的结果长度加2
						res = res>res1?res:res1;		//记录较长的结果
					}
					else
					{
						stackb.push(ch1);
						res2 = res1;				
						res1 = 0;
					}
				}
				else
				{
					stackb.push(ch1);
				}
			}
		return res;
	}
	
	public static void main(String[] args) {
		String str = "<<<>";
		System.out.println(longestValidStr(str));
	}
}
