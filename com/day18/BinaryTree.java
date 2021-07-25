package com.day18;

import java.util.Arrays;
import java.util.Hashtable;

class TreeNode
{
	int data;
	TreeNode left;
	TreeNode right;
	public TreeNode(int data) 
	{
		this.data = data;
		left = null;
		right = null;
	}
}


public class BinaryTree {
	
	public void preOderTraverse(TreeNode root) 
	{
		if(root != null)
		{
			System.out.println(root.data);
			preOderTraverse(root.left);
			preOderTraverse(root.right);
		}
	}
	
	public TreeNode rebuildTree(int[] pre,int[] in)
	{
		if(pre.length==0 || in.length==0)
			return null;	
		int[] pre1 = new int[pre.length];
		int[] pre2 = new int[pre.length];
		int[] in1 = new int[in.length];
		int[] in2 = new int[in.length];
		int i = 0;
		for(i=0; i<pre.length; i++)
		{
			if(in[i] == pre[0])
				break;
		}
		
		in1 = Arrays.copyOfRange(in, 0, i-1);
		pre1 = Arrays.copyOfRange(pre,1,i+1);
		
		in2 = Arrays.copyOfRange(in, i, in.length-1);
		pre2 = Arrays.copyOfRange(in, pre.length-1-i,pre.length-1);

		TreeNode t = new TreeNode(pre[0]);
		t.left = rebuildTree(pre1,in1);
		t.right = rebuildTree(pre2,in2);
		return t;
	}
	
	public static void main(String[] args) 
	{
		
		BinaryTree tree = new BinaryTree();
		int[]  pre = {1,2,4,3,5,7,6};
		int[] in = {2,4,1,5,7,3,6};
		//TreeNode tNode = tree.rebuildTree(pre, in);
		
		
		Hashtable<String, Integer> hashtable = new Hashtable<>();
		
		System.out.println("hello world");
	}
}
