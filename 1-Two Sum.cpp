/*
* As the solution is identical => elements in the vector are unique
* Using the unordered_map (key: element in the vector, value: index of element)
*/

#include<vector>
#include<unordered_map>
using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> temp;
        vector<int> res(2);        
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            unordered_map<int,int>::const_iterator ite = temp.find(target - nums[i]);
            if(ite == temp.end()){
                temp[nums[i]] = i;
            } else{
                res[0] = ite->second;
                res[1] = i;
                break;
            }
        }
        temp.clear();
        return res;
    }
};