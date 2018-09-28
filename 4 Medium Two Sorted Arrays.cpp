#include <algorithm>
using std::min;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total & 0x1){
            return findKth(nums1.cbegin(), nums1.size(), nums2.cbegin(), nums2.size(), total/2 + 1);
        } else{
            return (findKth(nums1.cbegin(), nums1.size(), nums2.cbegin(), nums2.size(), total/2) + findKth(nums1.cbegin(), nums1.size(), nums2.cbegin(), nums2.size(), total/2 + 1)) / 2;
        }
    }
private:
    double findKth(vector<int>::const_iterator ita, int counta, vector<int>::const_iterator itb, int countb, int k){
        if(counta > countb){
            return findKth(itb, countb, ita, counta, k);
        }
        if(counta == 0){
            return *(itb + k - 1);
        }
        if(k == 1){
            return min(*ita,*itb);
        }
        int pa = min(k/2,counta);
        int pb = k - pa;    
        if(*(ita + pa - 1) < *(itb + pb - 1)){
            return findKth(ita + pa, counta - pa, itb, countb, k - pa);
        } else if(*(ita + pa - 1) > *(itb + pb - 1)){
            return findKth(ita, counta, itb + pb, countb - pb, k - pb);
        } else{
            return *(ita + pa - 1);
        }
    }    
};