#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

// 从N个元素中等概率的选出K个
vector<int> sampling(int K, int N) 
{
    srand(time(NULL));//设置随机数种子，使每次产生的随机序列不同
    if (N < 1 || K < 1 || N < K) 
    {
        return {};
    }
    //构建数组，需要把第i个数放入数组
    vector<int> bag(K + 1);

    for (int i = 1; i <= K; i++) 
    {
        // 前K个数据直接放进数组中
        bag[i] = i;
    }

    // K+1个元素开始进行概率抽样
    for(int i = K; i <=N; i++) 
    {
        //剩下的数会有k/i的概率进入数组中，
        //产生从1~i的随机数，如果产生的随机数<=K，就说明中了概率
        if ((rand() % i+1) <= K)
        {
            //替换的下标
            int bagi = rand() % K + 1;
            bag[bagi] = i;
        }
    }
       
    return bag;
}

vector<int> sampling1(int N, int K) {
	//设置随机数种子，使每次产生的随机序列不同
	srand(time(NULL));
    if (N < 1 || K < 1 || N < K) 
    {
        return {};
    }
	//简化 
    vector<int> arr;
	for (int i = 1; i <= N; i++) {
		if (i <= K) {
			arr.push_back(i);
		} else {
			int j = rand()%i + 1;
			//以1/i的生成一个随机数j，j < k (概率为k/i), 让[1...k]中的第j个指针指向第i个数 
			if (j <= K) {					
				arr[j] = i;			
			} 		
			//否则跳过第i个数 
			else {
				
			}						
		}
	} 
	return arr;
} 

int main() {
	vector<int> res = sampling1(100,10);
	//1 53 91 40 98 6 56 8 43 96
	for (auto e : res) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
} 

