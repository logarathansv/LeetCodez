class Solution {
public:
    int isPossible(vector<int>& nums, int divisor){
        int sum = 0;
        for(auto num : nums){
            sum += ceil((float) num / divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(l <= h){
            int mid = (l+h)/2;
            if(isPossible(nums, mid) <= threshold) h = mid - 1;
            else l = mid + 1;
        }   
        return l;
    }
};