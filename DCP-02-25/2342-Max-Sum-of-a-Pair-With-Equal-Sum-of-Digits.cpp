class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int i=0, maxi = INT_MIN, sum=0, f = 0;
        unordered_map<int, vector<int>> sumofDigits;
        for(auto num:nums){
            string s = to_string(num);
            for(auto ch:s){
                sum += (ch - '0');
            }
            // cout<<"sum "<<sum<<'\n';
            sumofDigits[sum].push_back(i);
            // cout<<sum<<" "<<sumofDigits[sum].size();
            sum = 0;i++;
        }
        for(auto pair:sumofDigits){
            int n = sumofDigits[pair.first].size();
            if(n > 1){
                vector<int> temp = sumofDigits[pair.first];
                cout<<"temp "<<temp[0]<<temp[1]<<'\n';
                for(int j=0;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        int sumpair = nums[temp[j]] + nums[temp[k]];
                        maxi = max(maxi, sumpair);
                    }
                }
                f = 1;
            }
        }
        return f ? maxi : -1;
    }
};