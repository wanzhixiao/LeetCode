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
		//ͼ�Ĺ�����ȱ���
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
    			// ������һ������ 
    			if (ch == origin) continue;
    	
    			curWord[i] = ch;
    			string nextWord = curWord;
    			//�ҵ�Ŀ�굥��  	
    			if (dict.count(nextWord) != 0) {			//wordDict�а���Ŀ�굥�� 
	    			if (curWord == endWord) {
	//    				return dist[curWord] + 1;
						return true;
					}
					// �������� 
					if (!visited.count(nextWord)) {
//						cout <<curWord<< " nextWord="<<nextWord <<endl;
						visited.insert(nextWord);
						q.push(nextWord);
						//�����1�����Ϊ�����ʹ� 
	//					dist[nextWord] = dist[curWord] + 1;
						//�����ھ��б� 
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
���룺beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
�����5
���ͣ�һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog", �������ĳ��� 5��
*/ 
