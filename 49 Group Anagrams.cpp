#include <algorithm>
#include <unordered_map>
using std::unordered_map;
using std::sort;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> um;
        for(auto it = strs.cbegin(); it != strs.cend(); ++it){
            string temp = *it;
            sort(temp.begin(), temp.end());
            auto um_it = um.find(temp);
            if(um_it != um.end()){
                um_it->second.push_back(*it);
            } else{
                um[temp] = vector<string> (1,*it);
            }
        }
        for(auto it = um.cbegin(); it != um.cend(); ++it){
            res.push_back(it->second);
        }
        return res;
    }
};