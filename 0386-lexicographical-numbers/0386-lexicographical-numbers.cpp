class Solution {
public:
    static bool cmp(int a, int b){
        string a1 = to_string(a);
        string b1 = to_string(b);
        if(a1<b1) return true;
        else return false;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=0;i<n;i++) ans.push_back(i+1);
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};