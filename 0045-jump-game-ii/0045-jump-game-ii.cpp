class Solution {
public:
//     int mindist(int ind, vector<int>& nums, vector<int>& dp){
//         if(ind >= nums.size()-1) return 0;

//         if(dp[ind] != -1) return dp[ind];

//         int mini = INT_MAX;
//         for(int i=1;i<=nums[ind];i++){
//             if(ind + i < nums.size()){
//                 int minidist = mindist(ind + i, nums, dp);
//                 if(minidist == INT_MAX) continue;
//                 else minidist += 1; 
//                 mini = min(mini, minidist);
//             }
//         }
//         return dp[ind] = mini;
//     }
    int jump(vector<int>& nums) {
        // vector<int> dp(nums.size(), -1);
        int l = 0, r = 0, ct = 0;

        while(r<nums.size()-1){
            int far = 0;
            for(int i=l;i<=r;i++){
                far = max(far, i+nums[i]);
            }

            l = r+1;r = far;
            ct++;
        }

        return ct;
        // return mindist(0, nums, dp);
    }
};