class Solution {
public:
    int findtotal(vector<int> nums, int goal){
        if(goal<0) return 0;
        int sum = 0;
        int l=0,r=0;
        int tot = 0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum>goal){ 
                sum -= nums[l];
                l++;
            }
            tot = tot + (r-l+1);
            r++;
        }
        return tot;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0, currsum = 0;
        // Using map
        // unordered_map<int, int> mp;
        // for(auto num:nums){
        //     currsum += num;

        //     if(currsum == goal) res++;
        //     if(mp.find(currsum - goal) != mp.end()){
        //         res += mp[currsum - goal];
        //     }
        //     mp[currsum] ++;
        // }
        // Using Sliding Window
        res = findtotal(nums, goal) - findtotal(nums, goal-1);
        return res;
    }
};