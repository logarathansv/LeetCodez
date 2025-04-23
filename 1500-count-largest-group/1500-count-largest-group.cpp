class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        int ct = 0;

        for(int i=1;i<n+1;i++){
            int add = i%10;
            if(i > 9) add += (i/10)%10;
            if(i > 99) add += (i/100)%10;
            if(i > 999) add += (i/1000)%10;
            if(i > 9999) add += (i/10000)%10;

            mp[add]++;
            maxi = max(maxi, mp[add]);
        }
        for(auto ele : mp) if(ele.second == maxi) ct++;
        return ct;
    }
};