#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

// ��N��Ԫ���еȸ��ʵ�ѡ��K��
vector<int> sampling(int K, int N) 
{
    srand(time(NULL));//������������ӣ�ʹÿ�β�����������в�ͬ
    if (N < 1 || K < 1 || N < K) 
    {
        return {};
    }
    //�������飬��Ҫ�ѵ�i������������
    vector<int> bag(K + 1);

    for (int i = 1; i <= K; i++) 
    {
        // ǰK������ֱ�ӷŽ�������
        bag[i] = i;
    }

    // K+1��Ԫ�ؿ�ʼ���и��ʳ���
    for(int i = K; i <=N; i++) 
    {
        //ʣ�µ�������k/i�ĸ��ʽ��������У�
        //������1~i�����������������������<=K����˵�����˸���
        if ((rand() % i+1) <= K)
        {
            //�滻���±�
            int bagi = rand() % K + 1;
            bag[bagi] = i;
        }
    }
       
    return bag;
}

vector<int> sampling1(int N, int K) {
	//������������ӣ�ʹÿ�β�����������в�ͬ
	srand(time(NULL));
    if (N < 1 || K < 1 || N < K) 
    {
        return {};
    }
	//�� 
    vector<int> arr;
	for (int i = 1; i <= N; i++) {
		if (i <= K) {
			arr.push_back(i);
		} else {
			int j = rand()%i + 1;
			//��1/i������һ�������j��j < k (����Ϊk/i), ��[1...k]�еĵ�j��ָ��ָ���i���� 
			if (j <= K) {					
				arr[j] = i;			
			} 		
			//����������i���� 
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

