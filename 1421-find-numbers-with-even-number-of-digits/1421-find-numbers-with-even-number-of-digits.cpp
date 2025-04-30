class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums){
            if(((int)log10(num) + 1) % 2 == 0) ans++;
        }
        return ans;
    }
};