 #include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        sort(intervals.begin(),intervals.end(),
             [](const Interval &a,const Interval &b){
                 if(a.start != b.start){
                     return a.start < b.start;
                 }
                 return a.end < b.end;
             });
        
//        for(Interval inter : intervals){
//            if(ans.size()==0){
//                ans.push_back(inter);
//            }else{
//                Interval a = ans.back();
//                if(inter.start <= a.end && a.end < inter.end){
//                    Interval b(a.start,inter.end);
//                    ans.pop_back();
//                    ans.push_back(b);
//                }else if(inter.start > a.end){
//                    ans.push_back(inter);
//                }else if(inter.start > a.end && inter.end < a.end){
//                    continue;
//                }
//            }
//        }
		int len = intervals.size();
		if(len==0) return ans;
		for(int i=1;i<intervals.size();i++){
			if(intervals[i].start > intervals[i-1].end){
				ans.push_back(intervals[i-1]);
			}else{
				intervals[i].start = min(intervals[i].start,intervals[i-1].start);
				intervals[i].end = max(intervals[i].end,intervals[i-1].end);
			}
		}
		ans.push_back(intervals[len-1]);
        return ans;
    }
        
    	return ans;
    }
};

int main(){

	 
	return 0;
} 
