package backtrack;

import java.util.*;



/*
* 全排列2
* 对原数组进行排序
* 把每个位置看做一个深度
* 如果 i>0 && nums[i] == nums[i-1]
*
* 对于三个占位，如1,1,2不重复的全排列
* _,_,_
* 每个_对应递归树的一层, 可以放原数组中任何数字
*
* nums[i]既可以位于nums[i-1]的下一层，也可以与nums[i-1]同一层
* 层数是指 _,对应的下标 如nums[i-1],nums[i],_,的关系为下一层
* 当nums[i],nums[i-1], nums[i]位于原来nums[i-1]的层数，nums[i-1]为nums[i]的下一层。出现了重复
*
* 如 1,1',2 ; 1,1',2和 1',1, 2是第一层 分别放1,1'
*
* */
class Solution47 {
    List<List<Integer>> ans;
    public List<List<Integer>> permuteUnique(int[] nums) {
        ans = new ArrayList<>();
        Arrays.sort(nums);

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

            //判断条件保证了对于重复数的集合，一定是从左往右逐个填入的
            //对于同一个depth,数组中存在重复数字就舍去该数字,且第j-1个数未被使
            if(visited[j] || (j>0 && (nums[j] == nums[j-1]) && !visited[j-1])){
                continue;
            }

            visited[j] = true;
            deque.addLast(nums[j]);
            backtrack(nums,deque,visited,depth+1,n);
            deque.removeLast();
            visited[j] = false;

        }
    }
}


public class lc47 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] nums = new int[n];
        for(int i=0;i<n;i++){
            nums[i] = sc.nextInt();
        }

        Solution47 s = new Solution47();
        List<List<Integer>> ans = s.permuteUnique(nums);
        System.out.println(ans);

    }
}
