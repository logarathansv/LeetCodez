class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = (s.size() % k != 0) ? k - s.size()%k : 0;
        vector<string> ans;

        string str = "";

        for(int i=0;i< s.size() + n;i++){
            if(i < s.size()) str += s[i];
            else str += fill;

            if((i+1) % k == 0) {
                ans.push_back(str);
                str = "";
            }
        }
        cout<<str;

        return ans;
    }
};