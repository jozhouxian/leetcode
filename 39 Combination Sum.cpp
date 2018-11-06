#include <algorithm>
using std::sort;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size() == 0) {
            return res;
        }
        vector<int> res_cur;
        sort(candidates.begin(),candidates.end());
        backTracking(candidates, target, res, res_cur, 0);
        return res;
    }
private:
    void backTracking(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> res_cur, int last_pos){
        if(target == 0){
            res.push_back(res_cur);
        }
        for(int i = last_pos; i < candidates.size() && candidates[i] <= target; ++i){
            res_cur.push_back(candidates[i]);
            backTracking(candidates, target - candidates[i], res, res_cur, i);
            res_cur.pop_back();
        }
    }
};