class Solution {
private:
    int findIndex(vector<int> &nums, int left, int right, int target, bool isLeft = false){
        int mid = (left + right + (isLeft ? 0 : 1)) / 2;

        if (nums[mid] == target){
            if(isLeft &&  mid - 1 >= left && nums[mid - 1] == target){
                return findIndex(nums,left,mid-1,target,true);
            }
            if(!isLeft &&  mid + 1 <= right && nums[mid + 1] == target){
                return findIndex(nums,mid+1,right,target);
            }
            return mid;
        } else if(nums[mid] > target && ((mid - 1) >= left)){
            return findIndex(nums,left,mid-1,target,isLeft);
        } else if(nums[mid] < target && ((mid + 1) <= right)){
            return findIndex(nums,mid+1,right,target,isLeft);
        } else {
            return -1;
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.size() == 0){
            return res;
        }
        res[0] = findIndex(nums,0,nums.size() - 1,target,true);
        res[1] = findIndex(nums,0,nums.size() - 1,target);
        return res;
    }
};