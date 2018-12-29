class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        } else if(n == 1) {
            return nums[0];
        }
        int sum = nums[0];
        int max = nums[0];
        for(int i = 1; i < n; ++i){
            if(sum < 0){
                sum = nums[i];
            } else{
                sum += nums[i];
            }
            if(sum > max){
                max = sum;
            }
        }
        return max;
    }
};