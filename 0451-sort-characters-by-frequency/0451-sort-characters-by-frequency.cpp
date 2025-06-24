class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> arr('z' + 1, {0, 0});

        string ans;

        for(auto ch:s) {
            arr[ch].first++;
            arr[ch].second = ch;
        }

        sort(arr.begin(), arr.end());

        for(auto ele:arr){
            ans = string(ele.first, ele.second) + ans;
        }

        return ans;
    }
};