class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        //�߽�
        if(k==0 || arr.size() == 0){
            return vector<int>();
        }
       	//create heap
    	vector<int> heap(arr.begin(),arr.begin()+k);
    	
    	create_heap(heap);
		
		for(int i = k; i<arr.size(); i++){
			if(arr[i] < heap[0]){ //�󶥶���mink 
				heap[0] = arr[i]; //�滻�Ѷ� 
				heap_rify(heap,0,k); //�ӶѶ���ʼ���� 
			}
		}
		return heap;
    }
    
    
    void create_heap(vector<int> &arr){
    	int len = arr.size();
    	for(int i = len/2 - 1; i >= 0; i--){ //��len/2-1��ʼ���� 
    		heap_rify(arr,i,len);
		}
	}
	
	void heap_rify(vector<int> &arr, int cur, int len){
		//�󶥶��� min k
		//���������ϵ�
		int largest = cur;
		int left = 2*cur + 1;
		int right = 2*cur + 2;
		if(left < len && arr[left] > arr[largest]){
			largest = left;
		} 
		if(right < len && arr[right] > arr[largest]){
			largest = right;
		}
		if(largest != cur){
			int tmp = arr[cur];
			arr[cur] = arr[largest];
			arr[largest] = tmp;
			heap_rify(arr,largest,len);
		}	 
	} 
};

