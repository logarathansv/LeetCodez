class Solution {
public:
    void getHappyArr(int n, vector<string>& ans, string str){
        if(str.size() == n) {
            ans.push_back(str);
            cout<<"ans"<<str;
            return ;
        }
        cout<<"str"<<str;
        for(char ch='a';ch<='c';ch++){
            // cout<<"ind"<<ind<<" ";
            if(str.length() > 0 && ch == str[str.length()-1]) continue;
            // str += ch;
            getHappyArr(n, ans, str+ch);
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string str;

        getHappyArr(n, ans, "");
        return k-1 >= ans.size() ? "" : ans[k-1];
    }
};