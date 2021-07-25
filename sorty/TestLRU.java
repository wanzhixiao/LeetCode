package sorty;

import java.util.HashMap;
import java.util.Map;


//使用HashMap + LinkedList以要存储的key为key,以LinkedList的结点为value
class LRUCache{
	static class LinkedNode{
		int key;
		int value;
		LinkedNode next;
		LinkedNode prev;
		
		public LinkedNode() {}
		public LinkedNode(int key,int value) {
			this.key = key;
			this.value = value;
		}
	}
	
	Map<Integer, LinkedNode> map = new HashMap<>();
	
	
	
	public LRUCache(int capcity) {
		
	}
	
	public int get(int key) {
		return 0;
	}
	
	public void put(int key,int value) {
		
	}
}

public class TestLRU {
	public static void main(String[] args) {
		
	}
}
