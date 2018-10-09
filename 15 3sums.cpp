#include <algorithm>
using std::sort;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());

        auto it = nums.cbegin();
        do{
            if(it != nums.cbegin() && *it == *(it - 1)){
                ++it;
                continue;
            }
            auto first = it + 1;
            auto last = nums.cend() - 1;
            while (first < last) {
                if (*it + *first + *last == 0) {
                    vector<int> item = {*it, *first, *last};
                    res.push_back(item);
                    do{
                        ++first;
                    } while (*it + *first + *last == 0);
                } else if (*it + *first + *last < 0) {
                    do {
                        ++first;
                    } while (*it + *first + *last < 0);
                } else {
                    do {
                        --last;
                    } while (*it + *first + *last > 0);
                }
            }
            ++it;
        } while (*it <= 0 && it < (nums.cend() - 2));

        return res;
    }
};