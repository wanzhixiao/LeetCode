#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
	set<string> dict;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		dict = set<string>(wordList.begin(), wordList.end());
		dict.erase(beginWord);
		if (!dict.count(endWord)) {
			return 0;
		}	
		//图的广度优先遍历
		queue<string> q;
		q.push(beginWord);
		set<string> visited;
		visited.insert(beginWord);
		int step = 1;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				beginWord = q.front();
				q.pop();
				cout << beginWord << " " << step << endl;
				if (bfs(beginWord, endWord, q, visited)) {
                    return step+1;
                }
			}
			step += 1;
		}
		return 0;
    }
    
    bool bfs(string curWord,string endWord, queue<string> &q, set<string> &visited) {
    	
    	for (int i = 0, len1 = curWord.size(); i < len1; i++) {
    		char origin = curWord[i];
    		for (char ch = 'a'; ch <= 'z'; ch++) {
    			// 尝试下一个单词 
    			if (ch == origin) continue;
    	
    			curWord[i] = ch;
    			string nextWord = curWord;
    			//找到目标单词  	
    			if (dict.count(nextWord) != 0) {			//wordDict中包含目标单词 
	    			if (curWord == endWord) {
	//    				return dist[curWord] + 1;
						return true;
					}
					// 构建连边 
					if (!visited.count(nextWord)) {
//						cout <<curWord<< " nextWord="<<nextWord <<endl;
						visited.insert(nextWord);
						q.push(nextWord);
						//距离加1，标记为被访问过 
	//					dist[nextWord] = dist[curWord] + 1;
						//构建邻居列表 
					}	
				}
			}
			curWord[i] = origin;
		}
		return false;
	}
};

int main() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
	Solution solu;
	cout << solu.ladderLength(beginWord,endWord,wordList) << endl;
	return 0;
} 


/*
输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
*/ 
