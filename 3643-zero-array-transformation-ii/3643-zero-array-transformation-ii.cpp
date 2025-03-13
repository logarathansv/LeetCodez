class Solution {
public:
    bool isZero(vector<int>& nums, vector<int>& d, vector<vector<int>>& queries, int k){
        fill(d.begin(), d.end() , 0);
        for(int i=0;i<=k;i++){
            d[queries[i][0]] += queries[i][2];
            d[queries[i][1]+1] -= queries[i][2];
        }
        for(int i=1;i<d.size();i++){
            d[i] += d[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] > d[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if(all_of(nums.begin(), nums.end(), [](int i){return i == 0;})){
            return 0;
        }
        vector<int> d(nums.size()+1 , 0);
        int l = 0, r = queries.size()-1, res = -1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(isZero(nums, d, queries, mid)) {r = mid - 1; res = mid + 1;}
            else l = mid + 1;
        }
        return res;
    }
};