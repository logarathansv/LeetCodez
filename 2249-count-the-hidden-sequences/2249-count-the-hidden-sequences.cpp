class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> pref;
        pref.push_back(0);
        long long sum = 0;

        for(int i=0;i<differences.size();i++){
            sum += differences[i];
            pref.push_back(sum);
        }

        long long maxi = *max_element(pref.begin(), pref.end());
        long long mini = *min_element(pref.begin(), pref.end());
        long long inc = 0;
        cout<<"maxi "<<maxi<<'\n'<<"mini "<<mini;
        
        if(mini < lower){
            long long inc = (lower - mini);
            mini += inc;
            maxi += inc;
        }
        else if(maxi > upper) {
            long long dec = (maxi - upper);
            maxi -= dec;
            mini -= dec;
        }
        else if(mini >= lower && maxi <= upper){
            inc += min(abs(lower - mini), abs(upper - maxi));
        }
        
        cout<<"maxi "<<maxi<<'\n'<<"mini "<<mini;
        if(maxi > upper || mini < lower) return 0;
        return max(abs(upper-maxi) + inc + 1, abs(lower-mini) + inc + 1);
    }
};