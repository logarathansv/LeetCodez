class Solution {
public:

    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, st, curr;

        for(int i=0;i<arr.size();i++){
            curr.clear();
            curr.insert(arr[i]);
            for(auto p:prev){
                curr.insert(arr[i] | p);
            }

            prev = curr;
            st.insert(curr.begin(), curr.end());
        }

        return st.size();
    }
};