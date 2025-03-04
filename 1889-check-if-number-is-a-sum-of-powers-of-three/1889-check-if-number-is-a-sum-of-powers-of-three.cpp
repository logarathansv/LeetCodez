class Solution {
public:
    int helper(int n){
        int ans = 1;
        while(ans <= n){
            ans *= 3;
        }
        ans = (ans/3);
        return ans;
    }
    bool checkPowersOfThree(int n) {
        unordered_set<int> st;
        while(n > 0){
            int ans = helper(n);
            if(st.find(ans) != st.end()){
                return false;
            }
            cout<<ans<<" ";
            st.insert(ans);
            n -= ans;
        }
        return true;
    }
};