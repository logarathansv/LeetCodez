class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        int occur = -1;

        for(auto ar:arr){
            mp[ar]++;
        }

        for(auto ele:mp){ 
            if(st.find(ele.second) != st.end()) return false;
            st.insert(ele.second);
        }
        return true;
    }
};