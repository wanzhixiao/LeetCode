package leetcode.binary_search;


//理解二分查找
//https://blog.csdn.net/qq_19446965/article/details/82184672

class BinarySearch{

    //模板1
    //要点：left<=right,left=mid+1,right=mid+1,mid=left+(right-left)/2,return -1;
    public static int binSearch1(int[] nums,int key){
        //返回key在数组中的下标，未找到则返回-1

        //nums = {1,2,4,7,8,9,10}
        //1.找右边界
        //(1)查找到，key=10,
        //left=5,right=6,mid=5, nums[mid]<key,left=right+1=6
        //left=6,right=6,满足left<=right. mid=(left+right)/2=6
        //nums[mid]==key,直接返回
        //(2)未查找到，key = 11,最后一次查找，
        //while(left<=right)情况，退出循环的条件是找到key,或者，left = right+1
        //left=10,right=10,mid=10 -> nums[mid]=10 < 11,left=mid+1;
        //left=11,right=10,不满足left<=right,跳出循环，未找到，返回-1

        //2.找左边界
        //（1）查找到
        //key=1,最后一次查找，left=0,right=1,mid=(left+right)/2 = 0
        //此时，nums[mid] == key，直接返回
        //（2）未查找到
        //key = 0, 最后一次查找，left=0,right=1,mid=0
        //nums[mid]=1>key=0,right=mid-1=0
        //left=0,right=0,满足left<=right,mid=0,nums[mid]>key,right=mid-1=-1
        //left=0,right=-1,不满足left<=right,退出循环返回-1

        //2. while(left<right)情况，退出循环的条件是找到key,或者，left = right
        //循环条件是 left < right.查询区间是[left,right)
        //如果查询的key是10，则最后一次查询 left=5指向9，right=6指向10，a[left]<key,left=mid+1 = 10
        //下一次查找，left=10,right=10, 不满足left<right
        //跳出循环，返回-1

        int left = 0,right=nums.length-1;        //注意，right=数组长度-1,否则会发生数组越界
        while(left<=right){                     // <= 是左右闭区间[left,right],如果是<,是左闭右开区间[left,right)
            int mid = left + (right-left)/2;    //防止整数溢出
            if(nums[mid]==key){
                return mid;
            }else if(nums[mid]<key){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;      //未找到
    }

    //模板2，要点：left<right,left=mid-1,right=mid,mid=left+(right-left)/2,a[left]==key?left:-1, return -1;
    public static int binSearch2(int[] nums,int key) {
        //nums = {1,2,4,7,8,9,10},
        //1.找右边界
        //（1）查找到，key=10,最后一次查找
        //left=5,right=6,mid=5,a[mid]=9<10,
        //left=mid+1=6,不满足left<right，退出循环，
        //left=right=6,判断nums[left]==key,相等则找到并返回left，否则返回-1

        //(2)未找到，key = 11,最后一次查找，
        //left = 5,right=6,满足left<right,下一次查找
        //mid = (left+right)/2 = 5, nums[mid] = 9 < key
        //left = mid+1 = 6, right = 6, 不满足left<right,跳出循环，没有取到右边界 a[right]=10
        //退出循环时left==right,要判断右边界的值是否与key相等，即 left==nums.length-1 && nums[left]==key,找到
        //否则未找到


        //2.找左边界
        // (1)查找到，key=1,最后一次查找，left=0,right=1;
        //mid = (left+right)/2 = 0,a[mid]==key
        //找到直接返回
        //（2）未查找到，key=0,最后一次查找，left=0,right=1;
        //mid = (left+right)/2 = 0
        //a[mid]>key,right=mid=0,
        //left=0,right=0,不满足left<right,跳出循环
        //判断a[left]==key,不相等，返回-1

        int left = 0,right = nums.length-1;
        while(left<right){  // <
            int mid = left+(right-left)/2;
            if(nums[mid]==key){
                return mid;
            }
            else if(nums[mid]<key){
                left = mid+1;
            }else {
                right = mid;
            }
        }
        //此时 left==right
        return nums[left]==key?left:-1;
    }

    //返回第一个大于key的值，如果是边界则返回边界
    public static int upperBound(int[] nums,int key){
        int left = 0,right = nums.length-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]<=key){
                left = mid+1;
            }else {
                right = mid;
            }
        }
        //left=mid+1,如果nums[mid]==key,则nums[left]是下一个大于key的值
        //left<right,跳出循环前，left∈[0,nums.length-1),跳出循环后left∈[0,nums.lenght-1]
        return nums[left];
    }


    //返回第一个小于key的数
    public static int lowerBound(int[] nums,int key){
        int left = 0,right = nums.length-1;
        //退出循环时是left+1==right,且 left=mid<right,因为nums[mid]>=key时，有right=mid,那么，相等的时候是指向right的，第一个小于key的数就是left
        while(left+1<right){
            int mid = left+(right-left)/2;
            if(nums[mid]<key){
                left=mid;
            }else {
                right=mid;
            }
        }

        if(nums[right]<key){            //当key>nums[nums.length-1]时
            return nums[right];
        }
        return nums[left];
    }

    //
    public static int upper_bound1(int[] nums,int key){
        int left=0,right=nums.length-1;
        while(left+1<right){
            int mid = left + (right-left)/2;
            if(key>=nums[mid]){
                left = mid;
            }else{
                right = mid;
            }
        }
        if(nums[right]==key){   //key == nums[nums.length-1]时
            return -1;
        }
        return nums[right];            // 较小的left，较大的right
    }


}

public class binary_search {
    public static void main(String[] args) {
        int[] nums = {1,2,4,7,8,9,10};
        int key = 0;

//        System.out.println(BinarySearch.binSearch1(nums,key));      //2
//        System.out.println(BinarySearch.binSearch2(nums,key));      //2
//        System.out.println(BinarySearch.upperBound(nums,key));      //4
        System.out.println(BinarySearch.lowerBound(nums,key));      //1
        System.out.println(BinarySearch.upper_bound1(nums,key));      //1
    }
}
