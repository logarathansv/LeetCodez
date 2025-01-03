class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long rear = 0;
        for(auto num : nums) 
            rear += num;
        int ways = 0;
        long front = 0;
        for(int i=0;i<nums.size()-1;i++){
            front += nums[i];
            rear -= nums[i];
            if(front >= rear) ways++;
        }
        return ways;
    }
};