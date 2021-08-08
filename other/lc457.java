package other;

import java.util.*;

/*
* 判断有向图中是否存在环
* */
class Solution457 {
    /*
    *   0 -> 2 -> 4
    *   \'  \`    \'
    *    1 -> 3 <- 5
    * */
ArrayList<ArrayList<Integer>> graph ;
int[] degree = new int[5001];

public boolean toposort(int n){
    Queue<Integer> q = new LinkedList<>();
    //将所有入度为0的点如队列
    for(int i=0;i<n;i++){
        if(degree[i]==0){
            q.offer(i);
        }
    }
    //开始拓扑排序
    while(!q.isEmpty()){
        //取入度为0的点
        int cur = q.poll();
        //删除其与其他顶点的连边,同时这些顶点入度减一
        for(int x:graph.get(cur)){
            degree[x]--;
            //判断顶点的度是否为0，为0则加入队列
            if(degree[x]==0){
                q.offer(x);
            }
        }
    }
    //判断是否还有结点度不为0, 如果有则存在环
    for (int i=0;i<n;i++){
        if(degree[i] != 0){
            return true;
        }
    }
    return false;
}
    public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;
        graph = new ArrayList<ArrayList<Integer>>();

        for(int i=0;i<n;i++){
            graph.add(new ArrayList<Integer>());
            degree[i] = 0;
        }

        for(int i=0;i<n;i++){
            int end = ((i+nums[i])%n+n)%n;
            if(nums[i]<=0 ||i==end) continue;
            graph.get(i).add(end);
            degree[end]++;
        }

        if(toposort(n)){
            return true;
        }

        graph.clear();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<Integer>());
            degree[i] = 0;
        }

        for(int i=0;i<n;i++){
            int end = (((i+nums[i])%n+n)%n);
            if(nums[i]>=0 || i==end) continue;
            graph.get(i).add(end);
            degree[end]++;
        }

        if(toposort(n)){
            return true;
        }
        return false;
    }
}

public class lc457 {
    public static void main(String[] args) {
        int[] nums = {2,-1,1,2,2};
        Solution457 solu = new Solution457();
        boolean res = solu.circularArrayLoop(nums);
        System.out.println(res);
    }
}

//https://leetcode-cn.com/problems/circular-array-loop/solution/gtalgorithm-tuo-bu-zai-xian-by-gtalgorit-ah46/
/*
public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;
        int[] arr = new int[2 * n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
            arr[n + i] = nums[i];
        }

        HashMap<Integer, Integer> map = new HashMap<>();

        int slow = 0, fast = 0;

        for (slow = 0; slow < n; slow++) {
            fast = slow + arr[fast];
            while ((fast - n) < slow) {

                map.put(fast, arr[fast]);
                if (fast > n && arr[fast] == arr[slow]) {
                    if (map.size() > 1) {
                        int flag = 1;
                        for (Iterator iter = map.entrySet().iterator(); iter.hasNext(); ) {
                            Map.Entry<Integer, Integer> entry = (Map.Entry<Integer, Integer>) iter.next();
                            flag *= (entry.getValue() > 0) ? 1 : -1;
                            if (flag < 0) {
//                            return false;
                                break;
                            }
                        }
                        if (flag > 0) {
                            return true;
                        }
                    }
                }
                fast = fast + arr[fast];
            }
        }
        return false;
    }
* */
