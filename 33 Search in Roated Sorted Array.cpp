class Solution {
public:
    int search(vector<int> &nums, int target) {
        int res = -1;
        auto size = nums.size();

        if (size == 0) {
            return res;
        }

        res = getTarget(0, size - 1, nums, target);

        return res;
    }

private:
    int getTarget(unsigned long left, unsigned long right, vector<int> nums, int target) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        if (left == right){
            return -1;
        }

        if (nums[mid] > nums[right]) {
            if (target >= nums[left] && target <= nums[(mid - 1) > right ? left : (mid -1)]) {
                return getTarget(left, (mid - 1) > right ? left : (mid -1), nums, target);
            } else {
                return getTarget((mid + 1) > right ? right : (mid + 1), right, nums, target);
            }
        } else if (nums[mid] < nums[left]) {
            if (target >= nums[(mid + 1) > right ? right : (mid + 1)] && target <= nums[right]) {
                return getTarget((mid + 1) > right ? right : (mid + 1), right, nums, target);
            } else {
                return getTarget(left, (mid - 1) > right ? left : (mid -1), nums, target);
            }
        }
        if (target > nums[mid]) {
            return getTarget((mid + 1) > right ? right : (mid + 1), right, nums, target);
        } else if (target < nums[mid]){
            return getTarget(left, (mid - 1) > right ? left : (mid -1), nums, target);
        }
    }
};