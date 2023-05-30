#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
	set<string> dict;
public:
    vector<string> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		dict = set<string>(wordList.begin(), wordList.end());
		dict.erase(beginWord);
		if (!dict.count(endWord)) {
			return {};
		}	
		//图的广度优先遍历
		queue<string> q;
		q.push(beginWord);
//		set<string> visited;
//		visited.insert(beginWord);
		unordered_map<string,string> parent{{beginWord,""}};
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				string curWord = q.front();
				q.pop();
				if (bfs(curWord, endWord, q, parent)) {
					vector<string> ans;
					string x = endWord;			
					while (x != "") {
						ans.push_back(x);
						x = parent[x];
					}
					reverse(ans.begin(),ans.end());
					return ans;
                }
			}
		}
		return {};
    }
    
    bool bfs(string curWord,string endWord, queue<string> &q, unordered_map<string,string> &parent) {
    	
    	for (int i = 0, len1 = curWord.size(); i < len1; i++) {
    		char origin = curWord[i];
    		for (char ch = 'a'; ch <= 'z'; ch++) {
    			// 尝试下一个单词 
    			if (ch == origin) continue;
    			string nextWord = curWord;
    			nextWord[i] = ch;
//    			cout << nextWord << " ===== " << curWord << endl;
    			//找到目标单词  	
    			if (dict.count(nextWord) != 0) {			//wordDict中包含目标单词 
	    			if (nextWord == endWord) {
	//    				return dist[curWord] + 1;
						parent[nextWord] = curWord;
						return true;
					}
					// 构建连边 
					if (parent.find(nextWord) == parent.end()) {
//						cout <<curWord<< " nextWord= "<<nextWord <<endl;
//						visited.insert(nextWord);
						parent[nextWord] = curWord;
						q.push(nextWord);
						//距离加1，标记为被访问过 
	//					dist[nextWord] = dist[curWord] + 1;
						//构建邻居列表 
					}	
				}
			}
		}
		return false;
	}
};

int main() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
	Solution solu;
	vector<string> ans =  solu.ladderLength(beginWord,endWord,wordList);
	for (string &s : ans) {
		cout << s << "->";
	}
	cout << endl;
	return 0;
} 


/*
输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
*/ 
