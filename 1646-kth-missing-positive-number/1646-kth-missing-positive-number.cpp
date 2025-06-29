class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0, ct = 0;
        
        for(int i=1;i<= arr[arr.size()-1] && j<arr.size();i++){
            if(i != arr[j]) ct++;
            else j++;

            if(ct == k) return i;
        }

        if(k > ct) return arr[arr.size()-1] + (k - ct);
        return -1;
    }
};