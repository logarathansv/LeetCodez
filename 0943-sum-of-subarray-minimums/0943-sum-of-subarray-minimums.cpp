class Solution {
public:
    void findPSE(vector<int>& pse, vector<int>& arr){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }
    void findNSE(vector<int>& nse, vector<int>& arr){
        stack<int> st;
        for(int i=arr.size()-1;i>-1;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = (st.empty()) ? arr.size() : st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        long long MOD = 1000000007;
        vector<int> pse(arr.size());
        vector<int> nse(arr.size());

        findPSE(pse, arr);
        findNSE(nse, arr);

        for(int i=0;i<arr.size();i++){
            int l = i - pse[i];
            int r = nse[i] - i;

            sum = (sum + ((long long)l*r*arr[i])%MOD)%MOD; 
        }
        return sum;
    }
};