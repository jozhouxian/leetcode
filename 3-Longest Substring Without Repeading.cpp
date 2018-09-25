#include <queue>
#include <unordered_map>
using std::queue;
using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        
        for(string::const_iterator it = s.cbegin(); it != s.cend(); ++it){
            if(!um[*it]){
                q.push(*it);
                um[*it] = true;
                res = res > q.size() ? res : q.size();
            } else{
                while(q.front() != *it){
                    um[q.front()] = false;
                    q.pop();
                }
                q.pop();
                q.push(*it);
            }
        }
        return res;
    }
private:    
     queue<char> q;
     unordered_map<char,bool> um;
};