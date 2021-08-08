package graph;
/*
1).输入：一个加权连通图，其中顶点集合为V，边集合为E；
2).初始化：Vnew= {x}，其中x为集合V中的任一节点（起始点），Enew= {},为空；
3).重复下列操作，直到Vnew= V：
a.在集合E中选取权值最小的边<u, v>，其中u为集合Vnew中的元素，而v不在Vnew集合当中，
并且v∈V（如果存在有多条满足前述条件即具有相同权值的边，则可任意选取其中之一）；
b.将v加入集合Vnew中，将<u, v>边加入集合Enew中；
4).输出：使用集合Vnew和Enew来描述所得到的最小生成树。
* */

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Edge{
    int start;
    int end;
    int weight;
    public Edge(){}
    public Edge(int start,int end,int weight){
        this.start = start;
        this.end = end;
        this.weight = weight;
    }
}

class UnionFind{
    int[] root;
    public UnionFind(int n){
        root = new int[n];
        for(int i=0;i<n;i++){
            root[i] = i;
        }
    }
    public void uion(int x,int y){
        root[find(x)] = find(y);
    }
    public int find(int x){
        if(x != root[x]){
            root[x] = find(root[x]);
        }
        return root[x];
    }
}

class MST{
    //Prim 算法
    public ArrayList<Integer> prim(int[][] graph, int cur){
        int n = graph.length;

        int cost = 0;
        ArrayList<Integer> res = new ArrayList<>();

        boolean[] visited = new boolean[n];
        int[] dist = new int[n];

        res.add(cur);
        //第一个访问的结点
        visited[cur] = true;
        for(int i=0;i<n;i++){
            dist[i] = graph[cur][i];
        }
        for(int i=1;i<n;i++){               //剩余n-1个顶点
            int mindist = Integer.MAX_VALUE;
            int index=0;

            for(int j=0;j<n;j++){           //从当前顶点出发,找一个最近的未被访问过的顶点
                if(!visited[j] && dist[j]<mindist){
                    mindist = dist[j];
                    index = j;
                }
            }
            res.add(index);
            cost += mindist;
            visited[index] = true;
            //将以index为起点的点算进来,加入到当前集合，使新加入的顶点与当前集合的距离不为INF
            for(int k=0;k<n;k++){
                if(!visited[k] && graph[index][k]<dist[k]){
                    dist[k] = graph[index][k];
                }
            }
        }
        System.out.println("min cost tree:"+cost);
        return res;
    }

    //Kruskal 算法
    public ArrayList<Integer> kruskall(ArrayList<Edge> edges,int n_vertex){
        //对边进行排序？
        //每次找最小的边,并将边两端的顶点union到一个连通图
        //当边的数量等于顶点数量-1结束
        //对边的权重进行升序排序
        Collections.sort(edges, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.weight-o2.weight;
            }
        });

        UnionFind unionFind = new UnionFind(n_vertex);
        //选取边，并对边上的顶点进行union
        int cost = 0,edge_cnt = 0;
//        ArrayList<Integer> res = new ArrayList<>();
        for(Edge edge:edges){
            if(unionFind.find(edge.start) != unionFind.find(edge.end)){
                unionFind.uion(edge.start,edge.end);
                cost += edge.weight;
                edge_cnt++;
                if(edge_cnt == n_vertex-1){
                    break;
                }
            }
        }
        System.out.println("min cost tree:"+cost);
        return null;
    }
}

public class PrimAlg {
    private static int INF = Integer.MAX_VALUE;
    public static void main(String[] args) {
        int n = 0;          //number of vertex
        int[][] graph = {
                {INF, 6, 1, 5, INF, INF},
                {6, INF, 5, INF, 3, INF},
                {1, 5,  INF, 5,  6,  4},
                {5, INF, 5,  INF, INF,2},
                {INF,3,  6,  INF, INF,6},
                {INF,INF,4,  2,   6, INF}
        };

        MST obj = new MST();
        //Prim
        ArrayList<Integer> res = obj.prim(graph,n);
        for(Integer a:res){
            System.out.print(a+"->");
        }

        //Kruskal
        //构建边集合
        int n_vertex = graph.length;
        ArrayList<Edge> edges = new ArrayList<>();
        for(int i=0;i<n_vertex;i++){
            for(int j=0;j<n_vertex;j++){
                if(graph[i][j] != Integer.MAX_VALUE){
                    edges.add(new Edge(i,j,graph[i][j]));
                }
            }
        }
        System.out.println("\nnumber of edges:"+edges.size());
        obj.kruskall(edges,n_vertex);
    }
}
