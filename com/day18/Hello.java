package com.day18;

import java.util.HashSet;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Set;


class Solution {
    public boolean containsDuplicate(int[] nums) {
    	HashSet<Integer> hSet = new HashSet<>();
    	for(int i=0;i<nums.length;i++)
    	{
    		if(hSet.contains(nums[i]))
    		{
    			return true;
    		}
    		else
    			hSet.add(nums[i]);
    	}
        return false;
    }
}

public class Hello {
	public static void main(String[] args) {
		int[] nums= {1,2,3,4};
		
		Solution solution = new Solution();
		System.out.println(solution.containsDuplicate(nums));
		
	}
}
