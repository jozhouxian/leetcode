#include <algorithm>
using std::next_permutation;
using std::sort;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        do {
            vector<int> res_cur;
            for(auto it = nums.cbegin(); it != nums.cend(); ++it){
                res_cur.push_back(*it);
            }
            if(res_cur.size() > 0){
                res.push_back(res_cur);
            }
        } while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
};