package backtrack;

import java.util.*;

class Solution46 {
    List<List<Integer>> ans;
    public List<List<Integer>> permuteUnique(int[] nums) {
        ans = new ArrayList<>();
        Deque<Integer> deque = new ArrayDeque<>();
        boolean[] visited = new boolean[nums.length];
        backtrack(nums,deque,visited,0,nums.length);
        return ans;
    }
    public void backtrack(int nums[],Deque<Integer> deque,boolean[] visited, int depth,int n){
        if(depth==n){
            ans.add(new ArrayList<>(deque));
            return;
        }

        for(int j=0;j<n;j++){           //枚举每个元素, 每个元素都可以进入下一层，且下一层有n种选择
            if(!visited[j]){
                visited[j] = true;
                deque.addLast(nums[j]);
                backtrack(nums,deque,visited,depth+1,n);
                deque.removeLast();
                visited[j] = false;
            }
        }
    }
}

public class lc46 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] nums = new int[n];
        for(int i=0;i<n;i++){
            nums[i] = sc.nextInt();
        }

        Solution46 s = new Solution46();
        List<List<Integer>> ans = s.permuteUnique(nums);
        System.out.println(ans);

    }
}
