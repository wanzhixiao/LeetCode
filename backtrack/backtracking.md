题目：
力扣39，组合总和，https://leetcode-cn.com/problems/combination-sum/
力扣40，组合总和2，https://leetcode-cn.com/problems/combination-sum-ii/

思想：  
For 用于枚举子节点的可能性，所有子节点在同一层  
Dfs用于往下搜索（尝试）当发现不满足条件，往上一层  
搜索路径满足条件时，将路径加入结果集  

细节：枚举集合，startindex,排序，回退  
剪枝  
预剪枝   


模版  
Void backtrack(参数)｛  
后剪枝  
If(终止条件)｛  
存放结果  
Return;  
}  
For(选择：样本集合中的元素)  
｛  
	处理节点；  
	预剪枝  
	Backtrack(路径，选择列表)；	//递归  
	回溯，撤销处理结果  

｝  
｝  
