class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0, z1 = 0, z2 = 0;
        for(int num:nums1) {s1+=num;if(num == 0){ s1++;z1++;}}
        for(int num:nums2) {s2+=num;if(num == 0) {s2++;z2++;}}

        if(!z1 && s2 > s1 || !z2 && s1 > s2) return -1; 

        return max(s1, s2);
    }
};