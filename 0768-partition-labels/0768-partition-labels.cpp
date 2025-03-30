class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char ,int> mp;
        unordered_set<char> st;
        int ele = 0;
        for(auto ch:s){
            mp[ch]++;
        }
        for(int i=0;i<s.length();i++){
            st.insert(s[i]);
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            int f = 0;
            for(auto ele:st) if(mp.find(ele) != mp.end()) f = 1;
            if(!f) 
                if(ans.empty()) {ans.push_back(i+1);ele = i + 1;}
                else {ans.push_back(i + 1 - ele); ele = i + 1;}
        }
        return ans;
    }
};