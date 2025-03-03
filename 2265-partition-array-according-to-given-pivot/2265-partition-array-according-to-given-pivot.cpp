class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> great;
        vector<int> equal;
        for(auto num:nums){
            if(num < pivot){
                less.push_back(num);
            }
            else if(num > pivot){
                great.push_back(num);
            }
            else equal.push_back(num);
        }
        int ind = 0, indn = 0;
        while(indn < less.size()){
            nums[ind++] = less[indn++];
        }
        indn = 0;
        while(indn < equal.size()){
            nums[ind++] = equal[indn++];
        }
        indn = 0;
        while(indn < great.size()){
            nums[ind++] = great[indn++];
        }
        return nums;
    }
};