#include <algorithm>
#include <vector>
#include <string>
using std::vector;
using std::min;
using std::max;
class Solution {
private:
    int isOdd(int num) {
        return (num & 0x1);
    }
public:
    string longestPalindrome(string s) {
        int center = 0, rBound = -1, radius = 0, max_index = 0;
        vector<int> p(s.size()*2 + 1, 0);
        for(int i = 0; i <= s.size()*2; ++i){
            if(i <= rBound){
                radius = min(p[2 * center - i], rBound - i);
            } else{
                radius = 0;
            }
            while((i + radius) <= s.size()*2 &&
                  (i - radius) >= 0 &&
                  (isOdd(i - radius) ? s[(i - radius) / 2] : '#') == (isOdd(i + radius) ? s[(i + radius) / 2] : '#')){
                ++radius;
            }
            p[i] = radius;
            max_index = max(p[max_index], p[i]) == p[max_index] ? max_index : i;
            if(i + radius - 1 > rBound){
                center = i;
                rBound = i + radius - 1;
            }
        }

        return s.substr(max_index/2 - (p[max_index] - 1)/2, p[max_index] - 1);
    }
};
