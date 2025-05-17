class Solution {
public:
    void sortColors(vector<int>& nums) {
        int front = 0;
        int white = 0;
        int back = nums.size()-1;

        while(white <= back){
            if(nums[white] == 0) {swap(nums[front++], nums[white++]);}
            else if(nums[white] == 1) white++;
            else swap(nums[back--], nums[white]);
        }
    }
};