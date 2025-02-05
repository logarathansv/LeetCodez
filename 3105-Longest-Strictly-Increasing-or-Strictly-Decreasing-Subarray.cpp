class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, minc = 0, dec = 1, mdec = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] < nums[i+1]){
                (inc == 0) ? inc = inc+=2 : inc++;
                minc = max(inc, minc);
                dec = 0;
            }
            else if(nums[i] > nums[i+1]){
                (dec == 0) ? dec = dec+=2 : dec++;
                mdec = max(dec, mdec);
                inc = 0;
            }
            else{ inc = 1; dec = 1;}
        }
        return max(max(inc, minc), max(dec, mdec));
    }
};