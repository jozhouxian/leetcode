class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2){
        return;
    }
    bool if_exchanged = false;
    auto it_left = nums.end() - 1;
    while(it_left != nums.begin()){
        if(*it_left > *(--it_left)){
            if_exchanged = true;
            auto it_right = nums.end() - 1;
            do {
                if(*it_right > *it_left){
                    exchange(it_left, it_right);
                    break;
                }
            } while(it_left < (--it_right));
            break;
        }
    }

    reverse(it_left + (if_exchanged ? 1 : 0), nums.end() - 1);
    }
private:
    void exchange(vector<int>::iterator left, vector<int>::iterator right){
        *left = *left + *right;
        *right = *left - *right;
        *left = *left - *right;
    }
    void reverse(vector<int>::iterator left, vector<int>::iterator right){
        while(left < right){
            exchange(left, right);
            ++left;
            --right;
        }
    }   
};