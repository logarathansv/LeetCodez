class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0;
        int zct = 0, l = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) zct++;
            while(zct > k){
                if(nums[l] == 0)
                    zct--;
                l++;
            }
            len = max(len, i-l+1);
        }

        return len;
    }
};