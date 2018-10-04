class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, left = 0, right = height.size() - 1;
        int temp;
        while(left < right){
            if(height[left] < height[right]){
                temp = (right - left) * height[left];
                res = res > temp ? res : temp;
                ++left;
            } else{
                temp = (right - left) * height[right];
                res = res > temp ? res : temp;
                --right;
            }
        }
        return res;
    }
};