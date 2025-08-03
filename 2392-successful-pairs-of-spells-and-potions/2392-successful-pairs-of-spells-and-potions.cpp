class Solution {
public: 
    int findind(int spell, vector<int>& potions, long long success){
        int l = 0, h = potions.size()-1;

        while(l <= h){
            int mid = (l+h)/2;
            long long mul = 1LL * potions[mid] * spell;

            if(mul >= success) h = mid-1;
            else l = mid+1;
        }

        return l;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;

        sort(potions.begin(), potions.end());
        for(auto spell:spells){
            int idx = findind(spell, potions, success);
            ans.push_back(potions.size() - idx);
        }

        return ans;
    }
};