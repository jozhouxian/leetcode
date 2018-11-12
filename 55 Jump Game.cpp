#include <algorithm>
using std::max;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return true;
        
        int dest = 0;
        for(int i = 0; i < n; ++i) {
            if(dest >= n - 1)
                return true;
            if(i > dest)
                return false;
            dest = max(dest, i + nums[i]);    
        }
        return dest >= n - 1;
    }
};