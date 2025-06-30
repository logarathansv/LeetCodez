class Solution {
public:
    bool splitposs(int sum, int k, vector<int>& nums){
        int nk = 1;
        int curr = 0;

        for(int i=0;i<nums.size();i++){
            if(curr + nums[i] <= sum){
                curr += nums[i];
            }
            else{
                nk ++;
                curr = nums[i];
            }
        }

        return nk <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()); 
        int h = accumulate(nums.begin(), nums.end(), 0);

        while(l <= h){
            int mid =(l + h)/2;

            if(splitposs(mid, k, nums)) h = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
};