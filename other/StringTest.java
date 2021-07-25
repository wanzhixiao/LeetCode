package other;


public class StringTest {
	public static void main(String[] args) {
		String s1 = "hello";
		String s2 = "hel";
		String s3 = "lo";
		String s4 = s2+s3;
		
		String s5 = s2 + new String("lo");
		
		String s6 = new String("hello");
		String s7 = new String(s1);
		
		String s8 = s1+new String(s2);
		String s9 = "hello";
		
		System.out.println(s1==s4);		//false
		System.out.println(s1==s5); 	//false
		System.out.println(s1==s6);		//false
		System.out.println(s5==s6);		//false
		System.out.println(s1==s7);		//false
		System.out.println(s1==s6);		//false
		System.out.println(s1==s8);		//false
		System.out.println(s6==s7);		//false
		System.out.println(s1==s9);     //true
	}
}
