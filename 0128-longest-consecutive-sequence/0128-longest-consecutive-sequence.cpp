class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        int ct = 0, res = 1;

        unordered_set<int> st;
        for(auto num:nums) st.insert(num);

        for(auto num:st){
            if(st.find(num-1) == st.end()){
                int curr = 1;
                int i = num;

                while(st.find(i+1) != st.end()){
                    i += 1;
                    curr ++;
                }

                res = max(res, curr);
            }
        }

        return res;
    }
};