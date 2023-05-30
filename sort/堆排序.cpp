class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        //边界
        if(k==0 || arr.size() == 0){
            return vector<int>();
        }
       	//create heap
    	vector<int> heap(arr.begin(),arr.begin()+k);
    	
    	create_heap(heap);
		
		for(int i = k; i<arr.size(); i++){
			if(arr[i] < heap[0]){ //大顶堆求mink 
				heap[0] = arr[i]; //替换堆顶 
				heap_rify(heap,0,k); //从堆顶开始调整 
			}
		}
		return heap;
    }
    
    
    void create_heap(vector<int> &arr){
    	int len = arr.size();
    	for(int i = len/2 - 1; i >= 0; i--){ //从len/2-1开始调整 
    		heap_rify(arr,i,len);
		}
	}
	
	void heap_rify(vector<int> &arr, int cur, int len){
		//大顶堆求 min k
		//将大数往上调
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

