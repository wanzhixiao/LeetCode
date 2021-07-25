<<<<<<< HEAD
package dfs;

//冗余连接是指root[x] == root[y]
class Solution684 {

    class Union{
        private int[] root;
        private int[] path;
        Union(int n){
            root = new int[n];
            path = new int[n];
            for(int i=0;i<n;i++){
                root[i] = i;
            }
        }
        public boolean union(int x,int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX==rootY){
                return false;
            }
            if(path[rootX]<path[rootY]){        //将小树的根结点连接到大树的根结点,可以减少find的遍历时间
                root[rootX] = rootY;
                path[rootY] += 1;
            }else{
                root[rootY] = rootX;
                path[rootX] += 1;
            }
            return true;
        }

        public int find(int x){
            if(x != root[x]){
                root[x] = find(root[x]);
            }
            return root[x];
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        Union ufind = new Union(n+1);       //结点是从1开始的所以加1

        for(int[] edge:edges){
            if(!ufind.union(edge[0],edge[1])){
                return edge;
            }
        }
        return edges[0];
    }
}

public class lc684 {
    public static void main(String[] args) {
        int[][] edges = {{1,2},{1,3},{2,3}};
        Solution684 s = new Solution684();
        int[] res  = s.findRedundantConnection(edges);
        System.out.println(res[0]+" "+res[1]);
    }
}

/*
c++版本
class Solution {

    int u[2000];
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            u[i] = i;
        }
        vector<int> result(2,0);
        for(int i=0;i<edges.size();i++){
            vector<int> edge = edges[i];
            int root_x = find(edge[0]);
            int root_y = find(edge[1]);

            if(root_x == root_y){
                result[0] = edge[0];
                result[1] = edge[1];
            }else{
                combine(edge[0],edge[1]);
            }
        }
        return result;
    }

    int find(int x){
        while(x!=u[x]){
            u[x] = u[u[x]];
            x = u[x];
        }
        return u[x];
    }

    void combine(int x,int y){
        u[find(x)] = find(y);
    }

};
=======
package dfs;

//冗余连接是指root[x] == root[y]
class Solution684 {

    class Union{
        private int[] root;
        private int[] path;
        Union(int n){
            root = new int[n];
            path = new int[n];
            for(int i=0;i<n;i++){
                root[i] = i;
            }
        }
        public boolean union(int x,int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX==rootY){
                return false;
            }
            if(path[rootX]<path[rootY]){        //将小树的根结点连接到大树的根结点,可以减少find的遍历时间
                root[rootX] = rootY;
                path[rootY] += 1;
            }else{
                root[rootY] = rootX;
                path[rootX] += 1;
            }
            return true;
        }

        public int find(int x){
            if(x != root[x]){
                root[x] = find(root[x]);
            }
            return root[x];
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        Union ufind = new Union(n+1);       //结点是从1开始的所以加1

        for(int[] edge:edges){
            if(!ufind.union(edge[0],edge[1])){
                return edge;
            }
        }
        return edges[0];
    }
}

public class lc684 {
    public static void main(String[] args) {
        int[][] edges = {{1,2},{1,3},{2,3}};
        Solution684 s = new Solution684();
        int[] res  = s.findRedundantConnection(edges);
        System.out.println(res[0]+" "+res[1]);
    }
}

/*
c++版本
class Solution {

    int u[2000];
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            u[i] = i;
        }
        vector<int> result(2,0);
        for(int i=0;i<edges.size();i++){
            vector<int> edge = edges[i];
            int root_x = find(edge[0]);
            int root_y = find(edge[1]);

            if(root_x == root_y){
                result[0] = edge[0];
                result[1] = edge[1];
            }else{
                combine(edge[0],edge[1]);
            }
        }
        return result;
    }

    int find(int x){
        while(x!=u[x]){
            u[x] = u[u[x]];
            x = u[x];
        }
        return u[x];
    }

    void combine(int x,int y){
        u[find(x)] = find(y);
    }

};
>>>>>>> e94a879fa9b4dadf491dc10c450c622a214ecece
* */