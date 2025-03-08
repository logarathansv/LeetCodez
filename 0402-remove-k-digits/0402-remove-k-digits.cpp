class Solution {
public:
    string removeKdigits(string num, int k) {
        int start = 0;
        string ans;
        for(int i=0;i<num.size();i++){
            while(!ans.empty() && k > 0 && ans.back() > num[i]){
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }
        while(k>0 && !ans.empty()){
            ans.pop_back();
            k--;
        }
        while(start<ans.size() && ans[start] == '0'){
            start++;
        }
        cout<<ans;
        string res = ans.substr(start, ans.size()-start);
        return res == "" ? "0" : res ;
    }
};