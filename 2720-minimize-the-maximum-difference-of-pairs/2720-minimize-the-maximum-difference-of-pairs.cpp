class Solution {
public:
    int canPossible(vector<int>& nums, int thres){
        int ct = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] - nums[i] <= thres){
                ct++;
                i++;
            }
        }
        return ct;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0) return 0;
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums[nums.size()-1] - nums[0];
        while(l <= r){
            int mid = (l+r)/2;
            if(canPossible(nums, mid) >= p){
                r = mid-1;
            }
            else l = mid+1;
        }

        return l;
    }
};