有向图和无向图的环检测  
1.无向图  

并查集：检查每一条边的两个端点是否是相同的连通子图，如果是相同的，说明存在环；  

深度遍历：使用邻接矩阵，只需要用一个数组标记是否访问过，如果访问过且不是该节点的父节点，则有环；  

广度优先：可以；  

2.有向图  

拓扑排序：用一个队列记录入度为0的点，然后将他们去除时，另边的另一头节点的入度减一，不断记录入度为0的点，若最后没有入度不为0的点，则没有环，否则有环；不断的插入队尾，循环；  

深度遍历：和无向图不同的是，我们不能直接和无向图的深度遍历一样，因为有可能出现，一个节点同时是2个节点的孩子节点，但这个时候不是环，所以需要去除标记，或者使用三种标记：0代表节点没有访问过，-1代表节点被访问过一次，但它还有孩子节点未被访问完，1代表该节点的深度遍历已经结束；这种方法比较巧妙，不需要去除标记；  

广度优先：不可以，深度优先记录的是经过的路径，环出现在经过的路径上；

https://www.cnblogs.com/mdumpling/p/9494878.html  