
/*
1157.子数组中占绝大多数的元素

1. 方法： 暴力法
	线性统计arr[left...right+1]内每个元素的出现次数
	query次数太多，超时 
*/ 

class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.arr = arr

    def query(self, left: int, right: int, threshold: int) -> int:

        cnt = defaultdict()
        for i in range(left,right+1):
            if self.arr[i] not in cnt:
                cnt[self.arr[i]] = 1
            else:
                cnt[self.arr[i]] += 1
                
            if cnt[self.arr[i]] >= threshold:
                return self.arr[i]

        return -1

// 2.  二分查找     
class MajorityChecker {
private:
    vector<int> arr;
    unordered_map<int,vector<int>> mp;
    
    // 生成随机数 
    mt19937 gen{random_device{}()};
    static constexpr int k = 20;

public:
    MajorityChecker(vector<int>& arr) {
        this->arr = vector<int>(arr.begin(),arr.end());
        //统计每个数出现的次数，并加到map中 
        for (int i = 0, n = arr.size(); i < n; i++) {
            if (mp.count(arr[i]) == 0) {
                mp[arr[i]] = {i};
            } else {
                mp[arr[i]].push_back(i);
            }
        }
    }
    
    int query(int left, int right, int threshold) {
        int len = right-left+1;
        uniform_int_distribution<int> dis(left, right);
        //采样k(k=20)次 
        for (int i = 0; i < k; ++i) {
            //1.随机从arr中选一个数 , 从[left,right],  随机生成一个数 
            int x = arr[dis(gen)];
            vector<int>& vec = mp[x];

            int occ = bin_search(vec, right+1) - bin_search(vec, left);
            if (occ >= threshold) {
                return x;
            }
            //2. x的的出现次数超过数组的一半长度，但是小于threshold, 不满足要求
            // x，  arr[i1,i2,..ik]  
            //1,    [1,3,4]   threshold = 4
            //      right = 3, left = 2, len = right-left+1 = 2
            //3. 在left...right+1的区间中，x出现的次数occ小于threshold, 但是occ超过了left...right+1区间长度的一半,  因此，不可能有其他数y出现的次数大于occ, 不能满足条件 
            //occ = 2-1 = 1,  2*1 >= 2
            else if (2*occ >= len) {
                return -1;
            }
            //4. 如果 occ 小于区间长度的一半，那么需要再随机选择一个数并进行二分查找。
        }
        return -1;
    }

    int bin_search(vector<int> &indices, int target) {
        int low = -1, high = indices.size();
        while (low + 1 < high) {		//(left, right)
            int mid = low + (high - low)/2;
            if (indices[mid] >= target) {
                high = mid;
            } else {
                low = mid; 
            }
        }
        return high;
    }
};

/*
len = right-left+1, threshold
1.left...right+1  中出现某个数的次数occ大于 threshold;
2.left...right+1 中出现某个数的次数occ小于 threshold, 但occ >= (right-left+1)/2, 返回-1;
    occ < (right-left+1)/2, 从map中重新采样一个数y

*/

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
