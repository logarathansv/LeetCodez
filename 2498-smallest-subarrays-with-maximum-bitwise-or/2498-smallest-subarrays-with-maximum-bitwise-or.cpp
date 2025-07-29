class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> lastbits(32, -1);

        for(int i=n-1;i>=0;i--){
            for(int bit=0;bit<32;bit++){
                if((nums[i] >> bit) & 1){
                    lastbits[bit] = i;
                }
            }

            int maxind = i;

            for(int bit=0;bit<32;bit++){
                if(lastbits[bit] != -1)
                    maxind = max(lastbits[bit], maxind);
            }

            ans[i] = maxind - i + 1;
        }

        return ans;
    }
};