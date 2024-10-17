class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int mx = num, ind=0;
        for(int i=0;i<s.size();i++){
            int nm = (int)s[i] - 48;
            for(int j=i+1;j<s.size();j++){
                swap(s[i],s[j]);
                int curr = stoi(s);
                mx = max(mx, curr);
                swap(s[i],s[j]);
            }
        }

        return mx;
    }
};