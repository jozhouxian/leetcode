#include <algorithm>
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    static bool compare(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;   
        int n = intervals.size();
        if(n == 0) 
            return res;
        std::sort(intervals.begin(), intervals.end(),compare);
        res.push_back(intervals[0]);
        for(int i = 1; i < n; ++i){
            if(res.back().end < intervals[i].start){
                res.push_back(intervals[i]);
                continue;
            }
            res.back().end = std::max(res.back().end,intervals[i].end);   
        }
        return res;
    }
};