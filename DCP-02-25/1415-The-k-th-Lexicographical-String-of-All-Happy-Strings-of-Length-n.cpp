class Solution {
public:
    void getHappyArr(int k, int n, int& inc, string str, string& res){
        if(str.size() == n) {
            // ans.push_back(str);
            inc++;
            if(inc == k) res = str;
            return ;
        }
        cout<<"str"<<str;
        for(char ch='a';ch<='c';ch++){
            // cout<<"ind"<<ind<<" ";
            if(str.length() > 0 && ch == str[str.length()-1]) continue;
            str += ch;
            getHappyArr(k, n, inc, str, res);
            if(res != "") return;
            str.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        // vector<string> ans;
        string str;
        string res;
        int inc = 0;

        getHappyArr(k, n, inc, "", res);
        // return k > ans.size() ? "" : ans[k-1];
        return res;
    }
};