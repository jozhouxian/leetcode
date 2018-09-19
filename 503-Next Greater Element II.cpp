#include<stack>
#include<vector>
using std::vector;
using std::stack;

/*
* As the array is circular, each element need to
* compare with other elements
* Using a stack to store the index of previous element and 
* also show the priority
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        for(int i = 0, j = 0; i < 2*n-1; ++i) {
            j = i < n ? i : i - n;
            while(!st.empty() && nums[j] > nums[st.top()]) {
                res[st.top()] = nums[j];
                st.pop();
            }
            if(i < n) {
                st.push(i);
            }
        }   
        return res;
    }
};