class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;
        unordered_map<int,int> mp;
        int i=1;
        for(auto it:arr){
            st.insert(it);
        }
        for(auto it:st){
            mp[it] = i++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();