class Solution {
public:
    // bool findstr(string str, vector<string>& nums){
    //     for(auto num:nums){
    //         if(str == num) return false;
    //     }
    //     return true;
    // }
    void finddifferent(string str, vector<string>& nums, string& res, unordered_set<string> st){
        if(str.size() == nums[0].size()){
            if(st.find(str) == st.end()) res = str;
            return ;
        }
        if(res == ""){
            finddifferent(str + '0', nums, res, st);
            finddifferent(str + '1', nums, res, st);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // string res = "";
        // unordered_set<string> st; 
        // for(auto num:nums) st.insert(num);
        // finddifferent("", nums, res, st);
        // return res;

        //Diagonal Flipping
        string ans = "";
        for(int i=0;i<nums.size();i++){
            if(nums[i][i] == '0') ans += '1';
            else ans += '0';
        }    
        return ans;
    }
};