class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n > 0 && (n & (n - 1)) == 0) return true;
        vector<int> num;

        while(n > 0){
            num.push_back(n % 10);
            n /= 10;
        }

        sort(num.begin(), num.end());

        do{
            int res = 0;
            for(auto i : num) res = res*10 + i;
            int tp = res;
            int ct = 0;

            while(tp > 0) {ct++;tp/=10;}
            if(ct != num.size()) continue;

            if(res > 0 && (res & (res - 1)) == 0) return true;
        } while(next_permutation(num.begin(), num.end()));

        return false;
    }
};