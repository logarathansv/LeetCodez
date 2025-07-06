class FindSumPairs {
public:
    unordered_map<int, int> mp;
    vector<int> nums1;
    vector<int> nums2;

    FindSumPairs(vector<int>& num1, vector<int>& num2) {
        nums1 = num1;
        nums2 = num2;

        for(auto num:nums2) mp[num]++;
    }
    
    void add(int index, int val) {
        int newval = nums2[index];
        mp[newval] --;
        if(mp[newval] == 0) mp.erase(newval);

        nums2[index] += val;
        mp[newval + val]++;
    }
    
    int count(int tot) {
        int ct = 0;

        for(int i=0;i<nums1.size();i++){
            int target = tot - nums1[i];
            if(target < 0) continue;
            else{
                if(mp.find(target) != mp.end()) ct += mp[target];
            }
        }

        return ct;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */