
/*
1157.��������ռ���������Ԫ��

1. ������ ������
	����ͳ��arr[left...right+1]��ÿ��Ԫ�صĳ��ִ���
	query����̫�࣬��ʱ 
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

// 2.  ���ֲ���     
class MajorityChecker {
private:
    vector<int> arr;
    unordered_map<int,vector<int>> mp;
    
    // ��������� 
    mt19937 gen{random_device{}()};
    static constexpr int k = 20;

public:
    MajorityChecker(vector<int>& arr) {
        this->arr = vector<int>(arr.begin(),arr.end());
        //ͳ��ÿ�������ֵĴ��������ӵ�map�� 
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
        //����k(k=20)�� 
        for (int i = 0; i < k; ++i) {
            //1.�����arr��ѡһ���� , ��[left,right],  �������һ���� 
            int x = arr[dis(gen)];
            vector<int>& vec = mp[x];

            int occ = bin_search(vec, right+1) - bin_search(vec, left);
            if (occ >= threshold) {
                return x;
            }
            //2. x�ĵĳ��ִ������������һ�볤�ȣ�����С��threshold, ������Ҫ��
            // x��  arr[i1,i2,..ik]  
            //1,    [1,3,4]   threshold = 4
            //      right = 3, left = 2, len = right-left+1 = 2
            //3. ��left...right+1�������У�x���ֵĴ���occС��threshold, ����occ������left...right+1���䳤�ȵ�һ��,  ��ˣ���������������y���ֵĴ�������occ, ������������ 
            //occ = 2-1 = 1,  2*1 >= 2
            else if (2*occ >= len) {
                return -1;
            }
            //4. ��� occ С�����䳤�ȵ�һ�룬��ô��Ҫ�����ѡ��һ���������ж��ֲ��ҡ�
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
1.left...right+1  �г���ĳ�����Ĵ���occ���� threshold;
2.left...right+1 �г���ĳ�����Ĵ���occС�� threshold, ��occ >= (right-left+1)/2, ����-1;
    occ < (right-left+1)/2, ��map�����²���һ����y

*/

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
